module.exports = (ast, name, protocolHeaderPath, options) => {

    // "global" variables
    let hBuffer = '';
    let cppBuffer = '';
    let headerGuardName = '';
    let orderedStructNames = [];
    let indentation = '';
    let preposition = '';
    let supposition = '';
    const idlPrimitiveTypes = ['bool', 'byte', 'i8', 'i16', 'i32', 'i64', 'double', 'string', 'binary'];
    const idlToCppType = {
        'bool': 'bool',
        'byte': 'uint8_t',
        'i8': 'uint8_t',
        'i16': 'uint16_t',
        'i32': 'uint32_t',
        'i64': 'uint64_t',
        'double': 'double',
        'string': 'std::string',
        'binary': 'std::string',
        'list': 'std::vector',
        'set': 'std::set',
        'map': 'std::map'
    };

    // indentation
    const INCREASE_INDENTATION = () => { indentation += '    '; };
    const DECREASE_INDENTATION = () => { indentation.length < 4 ? indentation = '' : indentation = indentation.slice(0, -4); };

    // includes
    const writeIncludes = () => {
        // header file
        hBuffer += '#include <iostream>\n';
        hBuffer += '#include <map>\n';
        hBuffer += '#include <optional>\n';
        hBuffer += '#include <set>\n';
        hBuffer += '#include <stack>\n';
        hBuffer += '#include <stdexcept>\n';
        hBuffer += '#include <cstdint>\n';
        hBuffer += '#include <string>\n';
        hBuffer += '#include <vector>\n';
        hBuffer += '#include "' + protocolHeaderPath + '"\n\n';
        // cpp file
        cppBuffer += '#include "' + name + '.h"\n\n';
    };

    // header guards
    const getHeaderGuardName = () => {
        // name => THRIFT_NAME_H
        headerGuardName += 'THRIFT_';
        let upperName = name.toUpperCase();
        for (const char of upperName) {
            if (/^[A-Z0-9]*$/.test(char)) { headerGuardName += char; }
            else { headerGuardName += headerGuardName[-1] === '_' ? '' : '_'; }
        }
        headerGuardName += headerGuardName[-1] === '_' ? 'H' : '_H';
    };
    const writeHeaderGuardStart = () => {
        hBuffer += '#ifndef ' + headerGuardName + '\n';
        hBuffer += '#define ' + headerGuardName + '\n\n';
    };
    const writeHeaderGuardEnd = () => {
        hBuffer += '#endif // !' + headerGuardName;
    };

    // main namespace(s)
    const writeNamespaceStart = () => {
        if (ast.hasOwnProperty('namespace')) {
            if (ast.namespace.hasOwnProperty('cpp')) {
                let namespace = ast.namespace.cpp.serviceName.replace(/\./g, '::');
                hBuffer += 'namespace ' + namespace + ' {\n\n';
                cppBuffer += 'namespace '+ namespace + '{\n\n';
                INCREASE_INDENTATION();
            }
        }
    };
    const writeNamespaceEnd = () => {
        if (ast.hasOwnProperty('namespace')) {
            if (ast.namespace.hasOwnProperty('cpp')) {
                DECREASE_INDENTATION();
                hBuffer += '} // closing main namespace\n\n';
                cppBuffer += '} // closing main namespace\n\n';
            }
        }
    };

    // other namespaces / name alterations
    const writeReadStart = () => {
        if (options.namespaces.readWrite) {
            hBuffer += indentation + 'namespace read {\n\n';
            cppBuffer += indentation + 'namespace read {\n\n';
            INCREASE_INDENTATION();
        }
        else { preposition += 'read_'; }
    };
    const writeReadEnd = () => {
        if (options.namespaces.readWrite) {
            DECREASE_INDENTATION();
            hBuffer += indentation + '} // closing read namespace\n\n';
            cppBuffer += indentation + '} // closing read namespace\n\n';
        }
        else { preposition = preposition.slice(0, -5); } // read_
    };
    const writeWriteStart = () => {
        if (options.namespaces.readWrite) {
            hBuffer += indentation + 'namespace write {\n\n';
            cppBuffer += indentation + 'namespace write {\n\n';
            INCREASE_INDENTATION();
        }
        else { preposition += 'write_'; }
    };
    const writeWriteEnd = () => {
        if (options.namespaces.readWrite) {
            DECREASE_INDENTATION();
            hBuffer += indentation + '} // closing write namespace\n\n';
            cppBuffer += indentation + '} // closing write namespace\n\n';
        }
        else { preposition = preposition.slice(0, -6); } // write_
    };
    const writeRequestStart = () => {
        if (options.namespaces.requestResult) {
            hBuffer += indentation + 'namespace request {\n\n';
            cppBuffer += indentation + 'namespace request {\n\n';
            INCREASE_INDENTATION();
        }
        else { preposition += '_request'; }
    };
    const writeRequestEnd = () => {
        if (options.namespaces.requestResult) {
            DECREASE_INDENTATION();
            hBuffer += indentation + '} // closing request namespace\n\n';
            cppBuffer += indentation + '} // closing request namespace\n\n';
        }
        else { preposition = preposition.slice(0, -8); } // _request
    };
    const writeResultStart = () => {
        if (options.namespaces.requestResult) {
            hBuffer += indentation + 'namespace result {\n\n';
            cppBuffer += indentation + 'namespace result {\n\n';
            INCREASE_INDENTATION();
        }
        else { preposition += '_result'; }
    };
    const writeResultEnd = () => {
        if (options.namespaces.requestResult) {
            DECREASE_INDENTATION();
            hBuffer += indentation + '} // closing result namespace\n\n';
            cppBuffer += indentation + '} // closing result namespace\n\n';
        }
        else { preposition = preposition.slice(0, -7); } // _result
    };

    // get/check types/values
    const getCppType = (type) => {
        // primitive types
        if (idlPrimitiveTypes.includes(type)) { return idlToCppType[type]; }
        // struct or enum
        else if (typeof type === 'string') { return type; }
        // containers
        else if (type.name === 'list') { return 'std::vector<' + getCppType(type.valueType) + '>'; }
        else if (type.name === 'set') { return 'std::set<' + getCppType(type.valueType) + '>'; }
        else if (type.name === 'map') { return 'std::map<' + getCppType(type.keyType) + ', ' + getCppType(type.valueType) + '>'; }
        // error
        else { throw new Error('Invalid type: ' + type); }
    };
    const getDefaultValue = (type) => {
        // primitive type
        if (idlPrimitiveTypes.includes(type)) {
            if (type === 'string' || type === 'binary') {
                if (typeof options.defaults.string === 'number') { return '{' + options.defaults.string + '}'; }
                else if (options.defaults.string.length === 0) { return ''; }
                else { return '{"' + options.defaults.string + '"}'; }
            }
            else { return '{' + options.defaults[type] + '}'; }
        }
        // struct or enum
        else if (typeof type === 'string') {
            if (orderedStructNames.includes(type)) { return ''; }
            else { return '{' + type + '::' + options.defaults.enum_none_name + '}'; }
        }
        // containers
        else if (['list', 'set', 'map'].includes(type.name)) { return ''; }
        // error
        else { throw new Error('Invalid type: ' + type); }
    };
    const getCompactType = (type) => {
        // primitive type
        if (idlPrimitiveTypes.includes(type)) {
            if (type === 'i8') { return 'BYTE'; }
            else { return type.toUpperCase(); }
        }
        // struct or enum
        else if (typeof type === 'string') {
            if (orderedStructNames.includes(type)) { return 'STRUCT'; }
            else { return 'I32'; }
        }
        // containers
        else if (['list', 'set', 'map'].includes(type.name)) { return type.name.toUpperCase(); }
        // error
        else { throw new Error('Invalid type: ' + type); }
    };
    const checkIsDefinable = (type) => {
        // primitive type
        if (idlPrimitiveTypes.includes(type)) { return true; }
        // struct or enum
        else if (typeof type === 'string') {
            if (ast.hasOwnProperty('enum') && Object.keys(ast.enum).includes(type)) { return true; }
            else { return orderedStructNames.includes(type); }
        }
        // containers or error
        else {
            if (type.name === 'list' || type.name === 'set') { return checkIsDefinable(type.valueType); }
            else if (type.name === 'map') { return (checkIsDefinable(type.keyType) && checkIsDefinable(type.valueType)); }
            else { throw new Error('Invalid field type in struct: ' + type); }
        }
    };
    const countRequiredFields = (struct) => {
        let requiredFieldCount = 0;
        for (const field of struct) {
            if (field.hasOwnProperty('option') && field.option === 'required') { requiredFieldCount++; }
        }
        return requiredFieldCount;
    };
    const checkIsPodType = (type) => {
        if (idlPrimitiveTypes.includes(type) && !['string', 'binary'].includes(type)) { return true; }
        else if (ast.hasOwnProperty('enum')) { return Object.keys(ast.enum).includes(type); }
        else { return false; }
    };

    // write enums
    const writeEnums = () => {
        if (ast.hasOwnProperty('enum')) {
            for (const name of Object.keys(ast.enum)) {
                hBuffer += indentation + 'enum class ' + name + ' : uint32_t {\n';
                INCREASE_INDENTATION();
                // write initial none value
                hBuffer += indentation + options.defaults.enum_none_name + ' = ';
                if (options.defaults.enum_none_value === Infinity) { hBuffer += 'UINT32_MAX,\n'; }
                else { hBuffer += options.defaults.enum_none_value + ',\n'; }
                // write name value pairs
                for (const item of ast.enum[name].items) { hBuffer += indentation + item.name + ' = ' + item.value + ',\n'; }
                hBuffer = hBuffer.slice(0, -2) + '\n';
                DECREASE_INDENTATION();
                hBuffer += indentation + '};\n\n';
            }
        }
    };

    // write structs
    const orderStructs = () => {
        if (ast.hasOwnProperty('struct')) {
            let lastLength = 0;
            while (Object.keys(ast.struct).length > orderedStructNames.length) {
                for (const structName of Object.keys(ast.struct)) {
                    if (!orderedStructNames.includes(structName)) {
                        // check if all fields are defined
                        let definedFieldsCount = 0;
                        for (const field of ast.struct[structName]) {
                            definedFieldsCount += checkIsDefinable(field.type) ? 1 : 0;
                            // default -> optional
                            if ((!field.hasOwnProperty('option')) && options.treatDefaultAsOptional) { field.option = 'optional'; }
                        }
                        if (ast.struct[structName].length === definedFieldsCount) { orderedStructNames.push(structName); }
                    }
                }
                // if an infinite loop occurs
                if (orderedStructNames.length === lastLength) {throw new Error('Circular usage of structs within structs'); }
                else { lastLength = orderedStructNames.length; }
            }
        }
    };
    const writeStructs = () => {
        if (ast.hasOwnProperty('struct')) {
            for (const structName of orderedStructNames) {
                let struct = ast.struct[structName];
                hBuffer += indentation + 'struct ' + structName + ' {\n';
                INCREASE_INDENTATION();
                for (const field of struct) {
                    // optional/required
                    if (field.hasOwnProperty('option')) {
                        if (field.option === 'optional') { hBuffer += indentation + 'std::optional<' + getCppType(field.type) + '> ' + field.name + ';\n'; }
                        else if (field.option === 'required') { hBuffer += indentation + getCppType(field.type) + ' ' + field.name + getDefaultValue(field.type) + ';\n'; }
                        else { throw new Error('Invalid field option(' + field.option + ') in ' + structName + '.' + field.name); }
                    }
                    // default
                    else {
                        if (options.stdOptionalForDefault) { hBuffer += indentation + 'std::optional<' + getCppType(field.type) + '> ' + field.name + ';\n'; }
                        else { hBuffer += indentation + getCppType(field.type) + ' ' + field.name + getDefaultValue(field.type) + ';\n'; }
                    }
                }
                hBuffer += indentation + 'bool operator < (const ' + structName + '&) const { return false; }\n';
                DECREASE_INDENTATION();
                hBuffer += indentation + '};\n\n';
            }
        }
    };
    const writeExceptionStructs = () => {
        if (ast.hasOwnProperty('exception')) {
            // exceptions should not contain other exceptions, so declaration order doesn't matter
            for (const exceptionName of Object.keys(ast.exception)) {
                let exception = ast.exception[exceptionName];
                hBuffer += indentation + '// exception struct\n';
                hBuffer += indentation + 'struct ' + exceptionName + ' {\n';
                INCREASE_INDENTATION();
                for (const field of exception) {
                    // default -> optional
                    if ((!field.hasOwnProperty('option')) && options.treatDefaultAsOptional) { field.option = 'optional'; }
                    // optional/required
                    if (field.hasOwnProperty('option')) {
                        if (field.option === 'optional') { hBuffer += indentation + 'std::optional<' + getCppType(field.type) + '> ' + field.name + ';\n'; }
                        else if (field.option === 'required') { hBuffer += indentation + getCppType(field.type) + ' ' + field.name + getDefaultValue(field.type) + ';\n'; }
                        else { throw new Error('Invalid field option(' + field.option + ') in ' + exceptionName + '.' + field.name); }
                    }
                    // default
                    else {
                        if (options.stdOptionalForDefault) { hBuffer += indentation + 'std::optional<' + getCppType(field.type) + '> ' + field.name + ';\n'; }
                        else { hBuffer += indentation + getCppType(field.type) + ' ' + field.name + getDefaultValue(field.type) + ';\n'; }
                    }
                }
                DECREASE_INDENTATION();
                hBuffer += indentation + '};\n\n';
            }
        }
    };

    // write write types
    const writeWriteType = (type, varName, id, isInContainer) => {
        // primitive type
        if (idlPrimitiveTypes.includes(type)) { writeWritePrimitive(type, varName, id, isInContainer); }
        // struct or enum
        else if (typeof type === 'string') {
            if (orderedStructNames.includes(type)) { writeWriteStruct(type, varName, id, isInContainer); }
            else { writeWriteEnum(varName, id, isInContainer); }
        }
        // containers
        else if (type.name === 'list') { writeWriteList(type, varName, id, isInContainer); }
        else if (type.name === 'set') { writeWriteSet(type, varName, id, isInContainer); }
        else if (type.name === 'map') { writeWriteMap(type, varName, id, isInContainer); }
        // error
        else { throw new Error('Variable (' + varName + ') has invalid type: ' + type); }
    };
    const writeWritePrimitive = (type, varName, id, isInContainer) => {
        // bool
        if (type === 'bool') {
            if (isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeBool(_buffer, ' + varName + ');\n'; }
            else {
                cppBuffer += indentation + 'if (' + varName + ') ';
                cppBuffer += '{ TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::TRUE, ' + id + ', true); }\n';
                cppBuffer += indentation + 'else ';
                cppBuffer += '{ TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::FALSE, ' + id + ', false); }\n';
            }
        }
        // other primitive types
        else {
            let typeToFunc = {
                'byte': 'Byte',
                'i8': 'Byte',
                'i16': 'I16',
                'i32': 'I32',
                'i64': 'I64',
                'double': 'Double',
                'string': 'String',
                'binary': 'String'
            };
            if (!isInContainer) {
                cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::';
                cppBuffer += getCompactType(type) + ', ' + id + ');\n';
            }
            cppBuffer += indentation + 'TCompactProtocol::write' + typeToFunc[type] + '(_buffer, ' + varName + ');\n';
        }
        // end
        if (!isInContainer) { cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n'; }
    };
    const writeWriteEnum = (varName, id, isInContainer) => {
        if (isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeI32(_buffer, static_cast<uint32_t>(' + varName + '));\n'; }
        else {
            cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::I32, ' + id + ');\n';
            cppBuffer += indentation + 'TCompactProtocol::writeI32(_buffer, static_cast<uint32_t>(' + varName + '));\n';
            cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n';
        }
    };
    const writeWriteStruct = (type, varName, id, isInContainer) => {
        // get struct
        if (ast.hasOwnProperty('struct') && Object.keys(ast.struct).includes(type)) {
            let struct = ast.struct[type];
            // write begin
            if (!isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::STRUCT, ' + id + ');\n'; }
            cppBuffer += indentation + 'TCompactProtocol::writeStructBegin(_lastField);\n';
            // write fields
            for (const field of struct) {
                let fieldRequiredness = field.hasOwnProperty('option') ? field.option : 'default';
                let fieldIsUsingStdOptional = ((fieldRequiredness === 'optional') || (fieldRequiredness === 'default' && options.stdOptionalForDefault));
                let newVarName = varName + '.' + field.name;
                // check optional start
                if (fieldRequiredness === 'optional') {
                    cppBuffer += indentation + 'if (' + newVarName + '.has_value())\n';
                    cppBuffer += indentation + '{\n';
                    INCREASE_INDENTATION();
                }
                // write field
                if (fieldRequiredness === 'optional') { newVarName = '(*' + newVarName + ')'; }
                else if (fieldIsUsingStdOptional) { // default
                    if (options.missingDefaultOnWrite) { newVarName += 'value()'; }
                    else { newVarName = '(*' + newVarName + ')'; }
                }
                writeWriteType(field.type, newVarName, field.id, false);
                // check optional end
                if (fieldRequiredness === 'optional') {
                    DECREASE_INDENTATION();
                    cppBuffer += indentation + '}\n';
                }
            }
            // write end
            cppBuffer += indentation + 'TCompactProtocol::writeFieldStop(_buffer);\n';
            cppBuffer += indentation + 'TCompactProtocol::writeStructEnd(_lastField);\n';
            if (!isInContainer) { cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n'; }
        }
        else { throw new Error('Struct (' + type + ') does not exist'); }
    };
    const writeWriteException = (type, varName, id) => {
        // get exception
        if (ast.hasOwnProperty('exception') && Object.keys(ast.exception).includes(type)) {
            let exception = ast.exception[type];
            // write begin
            cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::STRUCT, ' + id + ');\n';
            cppBuffer += indentation + 'TCompactProtocol::writeStructBegin(_lastField);\n';
            // write fields
            for (const field of exception) {
                let fieldRequiredness = field.hasOwnProperty('option') ? field.option : 'default';
                let fieldIsUsingStdOptional = ((fieldRequiredness === 'optional') || (fieldRequiredness === 'default' && options.stdOptionalForDefault));
                let newVarName = varName + '.' + field.name;
                // check optional start
                if (fieldRequiredness === 'optional') {
                    cppBuffer += indentation + 'if (' + newVarName + '.has_value())\n';
                    cppBuffer += indentation + '{\n';
                    INCREASE_INDENTATION();
                }
                // write field
                if (fieldRequiredness === 'optional') { newVarName = '(*' + newVarName + ')'; }
                else if (fieldIsUsingStdOptional) { // default
                    if (options.missingDefaultOnWrite) { newVarName += 'value()'; }
                    else { newVarName = '(*' + newVarName + ')'; }
                }
                writeWriteType(field.type, newVarName, field.id, false);
                // check optional end
                if (fieldRequiredness === 'optional') {
                    DECREASE_INDENTATION();
                    cppBuffer += indentation + '}\n';
                }
            }
            // write end
            cppBuffer += indentation + 'TCompactProtocol::writeFieldStop(_buffer);\n';
            cppBuffer += indentation + '// TCompactProtocol::writeStructEnd(_lastField);\n';
            cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n';
        }
        else { throw new Error('Exception (' + type + ') does not exist'); }
    };
    const writeWriteList = (type, varName, id, isInContainer) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName += '_';
        // begin
        if (!isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::LIST, ' + id + ');\n'; }
        cppBuffer += indentation + 'TCompactProtocol::writeListBegin(_buffer, TCompactType::' + getCompactType(type.valueType) + ', ' + varName + '.size());\n';
        // write elements
        cppBuffer += indentation + 'for (auto& ' + loopName + ' : ' + varName + ')\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeWriteType(type.valueType, loopName, id, true);
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
        // end
        cppBuffer += indentation + '// TCompactProtocol::writeListEnd();\n';
        if (!isInContainer) { cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n'; }
    };
    const writeWriteSet = (type, varName, id, isInContainer) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName += '_';
        // begin
        if (!isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::SET, ' + id + ');\n'; }
        cppBuffer += indentation + 'TCompactProtocol::writeSetBegin(_buffer, TCompactType::' + getCompactType(type.valueType) + ', ' + varName + '.size());\n';
        // write elements
        cppBuffer += indentation + 'for (auto& ' + loopName + ' : ' + varName + ')\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeWriteType(type.valueType, loopName, id, true);
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
        // end
        cppBuffer += indentation + '// TCompactProtocol::writeSetEnd();\n';
        if (!isInContainer) { cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n'; }
    };
    const writeWriteMap = (type, varName, id, isInContainer) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName += '_';
        // begin
        if (!isInContainer) { cppBuffer += indentation + 'TCompactProtocol::writeFieldBegin(_buffer, _lastField, TCompactType::MAP, ' + id + ');\n'; }
        cppBuffer += indentation + 'TCompactProtocol::writeMapBegin(_buffer, TCompactType::' + getCompactType(type.keyType);
        cppBuffer += ', TCompactType::' + getCompactType(type.valueType) + ', ' + varName + '.size());\n';
        // write elements
        cppBuffer += indentation + 'for (auto& ' + loopName + ' : ' + varName + ')\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeWriteType(type.keyType, loopName + '.first', id, true);
        writeWriteType(type.valueType, loopName + '.second', id, true);
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
        // end
        cppBuffer += indentation + '// TCompactProtocol::writeMapEnd();\n';
        if (!isInContainer) { cppBuffer += indentation + '// TCompactProtocol::writeFieldEnd();\n'; }
    };

    // write read types
    const writeReadType = (type, varName, isInContainer) => {
        // primitive type
        if (idlPrimitiveTypes.includes(type)) { writeReadPrimitive(type, varName, isInContainer); }
        // struct or enum
        else if (typeof type === 'string') {
            if (orderedStructNames.includes(type)) { writeReadStruct(type, varName); }
            else { writeReadEnum(type, varName); }
        }
        // containers
        else if (type.name === 'list') { writeReadList(type, varName); }
        else if (type.name === 'set') { writeReadSet(type, varName); }
        else if (type.name === 'map') { writeReadMap(type, varName); }
        // error
        else { throw new Error('Variable (' + varName + ') has invalid type: ' + type); }
    };
    const writeReadPrimitive = (type, varName, isInContainer) => {
        // bool
        if (type === 'bool') {
            if (isInContainer) { cppBuffer += indentation + 'TCompactProtocol::readBool(_buffer, ' + varName + ');\n'; }
            else { cppBuffer += indentation + varName + ' = (_compactType_placeholder == TCompactType::TRUE);\n'; }
        }
        // other primitives
        else {
            let typeToFunc = {
                'byte': 'Byte',
                'i8': 'Byte',
                'i16': 'I16',
                'i32': 'I32',
                'i64': 'I64',
                'double': 'Double',
                'string': 'String',
                'binary': 'String'
            };
            cppBuffer += indentation + 'TCompactProtocol::read' + typeToFunc[type] + '(_buffer, ' + varName + ');\n';
        }
    };
    const writeReadEnum = (type, varName) => {
        cppBuffer += indentation + 'TCompactProtocol::readI32(_buffer, _enum_placeholder);\n';
        cppBuffer += indentation + varName + ' = static_cast<' + type + '>(_enum_placeholder);\n';
    };
    const writeReadStruct = (type, varName) => {
        // get struct
        if (ast.hasOwnProperty('struct') && Object.keys(ast.struct).includes(type)) {
            let struct = ast.struct[type];
            cppBuffer += indentation + 'TCompactProtocol::readStructBegin(_lastField);\n';
            // loop through fields
            if (options.exceptions.missingRequiredOnRead && countRequiredFields(struct) > 0) { cppBuffer += indentation + 'uint_fast16_t required_field_count = 0;\n'; }
            cppBuffer += indentation + 'while (true)\n';
            cppBuffer += indentation + '{\n';
            INCREASE_INDENTATION();
            cppBuffer += indentation + 'TCompactProtocol::readFieldBegin(_buffer, _lastField, _compactType_placeholder);\n';
            // check for STOP and then fids
            cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::STOP) { break; }\n';
            cppBuffer += indentation + 'switch (_lastField.top())\n';
            cppBuffer += indentation + '{\n';
            // cases
            for (const field of struct) {
                // new var name
                let fieldRequiredness = field.hasOwnProperty('option') ? field.option : 'default';
                let fieldIsUsingStdOptional = ((fieldRequiredness === 'optional') || (fieldRequiredness === 'default' && options.stdOptionalForDefault));
                let newVarName = varName + '.' + field.name;
                // case
                cppBuffer += indentation + 'case ' + field.id + ':\n';
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                if (options.checkFtypeOnRead) {
                    cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::' + getCompactType(field.type) + ')\n';
                    cppBuffer += indentation + '{\n';
                    INCREASE_INDENTATION();
                }
                // initialise field, read data, and mark required fields
                if (fieldIsUsingStdOptional) {
                    cppBuffer += indentation + newVarName + ' = ' + getCppType(field.type) + '{};\n';
                    newVarName = '(*' + newVarName + ')';
                }
                writeReadType(field.type, newVarName, false);
                if (fieldRequiredness === 'required' && options.exceptions.missingRequiredOnRead) {
                    cppBuffer += indentation + '++required_field_count;\n';
                }
                if (options.checkFtypeOnRead) {
                    DECREASE_INDENTATION();
                    cppBuffer += indentation + '}\n';
                    cppBuffer += indentation + 'else { TCompactProtocol::skip(_buffer, _compactType_placeholder, false); }\n'
                }
                cppBuffer += indentation + 'break;\n';
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n';
            }
            // default case
            cppBuffer += indentation + 'default:\n';
            cppBuffer += indentation + '{\n';
            INCREASE_INDENTATION();
            cppBuffer += indentation + 'TCompactProtocol::skip(_buffer, _compactType_placeholder, false);\n';
            cppBuffer += indentation + 'break;\n';
            DECREASE_INDENTATION();
            cppBuffer += indentation + '}\n';
            // end switch and while
            cppBuffer += indentation + '}\n';
            DECREASE_INDENTATION();
            cppBuffer += indentation + '}\n';
            // check required fields were all there
            if (options.exceptions.missingRequiredOnRead && countRequiredFields(struct) > 0) {
                cppBuffer += indentation + 'if (required_field_count != ' + countRequiredFields(struct) + ')\n';
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                cppBuffer += indentation + 'std::string error_string = "Missing REQUIRED fields (";\n';
                cppBuffer += indentation + 'error_string += std::to_string(required_field_count);\n';
                cppBuffer += indentation + 'error_string += "/' + countRequiredFields(struct) + ') read from ' + type + '";\n';
                cppBuffer += indentation + 'throw std::runtime_error(error_string);\n';
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n';
            }
            // write end
            cppBuffer += indentation + 'TCompactProtocol::readStructEnd(_lastField);\n';
        }
        else { throw new Error('Struct (' + type + ') does not exist'); }
    };
    const writeReadException = (type, varName) => {
        // get exception
        if (ast.hasOwnProperty('exception') && Object.keys(ast.exception).includes(type)) {
            let exception = ast.exception[type];
            cppBuffer += indentation + 'TCompactProtocol::readStructBegin(_lastField);\n';
            // loop through fields
            if (options.exceptions.missingRequiredOnRead && countRequiredFields(exception) > 0) { cppBuffer += indentation + 'uint_fast16_t required_field_count = 0;\n'; }
            cppBuffer += indentation + 'while (true)\n';
            cppBuffer += indentation + '{\n';
            INCREASE_INDENTATION();
            cppBuffer += indentation + 'TCompactProtocol::readFieldBegin(_buffer, _lastField, _compactType_placeholder);\n';
            // check for STOP and then fids
            cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::STOP) { break; }\n';
            cppBuffer += indentation + 'switch (_lastField.top())\n';
            cppBuffer += indentation + '{\n';
            // cases
            for (const field of exception) {
                // new var name
                let fieldRequiredness = field.hasOwnProperty('option') ? field.option : 'default';
                let fieldIsUsingStdOptional = ((fieldRequiredness === 'optional') || (fieldRequiredness === 'default' && options.stdOptionalForDefault));
                let newVarName = varName + '.' + field.name;
                // case
                cppBuffer += indentation + 'case ' + field.id + ':\n';
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                if (options.checkFtypeOnRead) {
                    cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::' + getCompactType(field.type) + ')\n';
                    cppBuffer += indentation + '{\n';
                    INCREASE_INDENTATION();
                }
                // initialise field, read data, and mark required fields
                if (fieldIsUsingStdOptional) {
                    cppBuffer += indentation + newVarName + ' = ' + getCppType(field.type) + '{};\n';
                    newVarName = '(*' + newVarName + ')';
                }
                writeReadType(field.type, newVarName, false);
                if (fieldRequiredness === 'required' && options.exceptions.missingRequiredOnRead) {
                    cppBuffer += indentation + '++required_field_count;\n';
                }
                if (options.checkFtypeOnRead) {
                    DECREASE_INDENTATION();
                    cppBuffer += indentation + '}\n';
                    cppBuffer += indentation + 'else { TCompactProtocol::skip(_buffer, _compactType_placeholder, false); }\n'
                }
                cppBuffer += indentation + 'break;\n';
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n';
            }
            // default case
            cppBuffer += indentation + 'default:\n';
            cppBuffer += indentation + '{\n';
            INCREASE_INDENTATION();
            cppBuffer += indentation + 'TCompactProtocol::skip(_buffer, _compactType_placeholder, false);\n';
            cppBuffer += indentation + 'break;\n';
            DECREASE_INDENTATION();
            cppBuffer += indentation + '}\n';
            // end while and switch
            cppBuffer += indentation + '}\n';
            DECREASE_INDENTATION();
            cppBuffer += indentation + '}\n';
            // check required fields were all there
            if (options.exceptions.missingRequiredOnRead && countRequiredFields(exception) > 0) {
                cppBuffer += indentation + 'if (required_field_count != ' + countRequiredFields(exception) + ')\n';
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                cppBuffer += indentation + 'std::string error_string = "Missing REQUIRED fields (";\n';
                cppBuffer += indentation + 'error_string += std::to_string(required_field_count);\n';
                cppBuffer += indentation + 'error_string += "/' + countRequiredFields(exception) + ') read from ' + type + '";\n';
                cppBuffer += indentation + 'throw std::runtime_error(error_string);\n';
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n';
            }
            // write end
            cppBuffer += indentation + 'TCompactProtocol::readStructEnd(_lastField);\n';
        }
        else { throw new Error('Struct (' + type + ') does not exist'); }
    };
    const writeReadList = (type, varName) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName = '_' + loopName + '_';
        // write variables
        cppBuffer += indentation + 'uint32_t ' + loopName + 'list_size = 0;\n';
        cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'placeholder;\n';
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'blank;\n'; }
        // read data
        cppBuffer += indentation + 'TCompactProtocol::readListBegin(_buffer, _compactType_placeholder, ' + loopName + 'list_size);\n';
        cppBuffer += indentation + 'for (uint_fast32_t i = 0; i < ' + loopName + 'list_size; ++i)\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeReadType(type.valueType, loopName + 'placeholder', true);
        cppBuffer += indentation + varName + '.push_back(' + loopName + 'placeholder);\n';
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + loopName + 'placeholder = ' + loopName + 'blank;\n'; }
        else if (['STRING', 'BINARY', 'LIST', 'SET', 'MAP'].includes(getCompactType(type.valueType))) { cppBuffer += indentation + loopName + 'placeholder.clear();\n'; }
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
    };
    const writeReadSet = (type, varName) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName = '_' + loopName + '_';
        // write variables
        cppBuffer += indentation + 'uint32_t ' + loopName + 'set_size = 0;\n';
        cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'placeholder;\n';
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'blank;\n'; }
        // read data
        cppBuffer += indentation + 'TCompactProtocol::readSetBegin(_buffer, _compactType_placeholder, ' + loopName + 'set_size);\n';
        cppBuffer += indentation + 'for (uint_fast32_t i = 0; i < ' + loopName + 'set_size; ++i)\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeReadType(type.valueType, loopName + 'placeholder', true);
        cppBuffer += indentation + varName + '.insert(' + loopName + 'placeholder);\n';
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + loopName + 'placeholder = ' + loopName + 'blank;\n'; }
        else if (['STRING', 'BINARY', 'LIST', 'SET', 'MAP'].includes(getCompactType(type.valueType))) { cppBuffer += indentation + loopName + 'placeholder.clear();\n'; }
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
    };
    const writeReadMap = (type, varName) => {
        // generate loop name
        let loopName = '';
        for (const char of varName) {
            if (['.', '*', '(', ')'].includes(char)) { loopName += '_'; }
            else { loopName += char; }
        }
        loopName = '_' + loopName + '_';
        // write variables
        cppBuffer += indentation + 'uint32_t ' + loopName + 'map_size = 0;\n';
        cppBuffer += indentation + getCppType(type.keyType) + ' ' + loopName + 'key_placeholder;\n';
        cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'value_placeholder;\n';
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + getCppType(type.keyType) + ' ' + loopName + 'key_blank;\n'; }
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + getCppType(type.valueType) + ' ' + loopName + 'value_blank;\n'; }
        // read data
        cppBuffer += indentation + 'TCompactProtocol::readMapBegin(_buffer, _compactType_placeholder, _compactType_placeholder, ' + loopName + 'map_size);\n';
        cppBuffer += indentation + 'for (uint_fast32_t i = 0; i < ' + loopName + 'map_size; ++i)\n';
        cppBuffer += indentation + '{\n';
        INCREASE_INDENTATION();
        writeReadType(type.keyType, loopName + 'key_placeholder', true);
        writeReadType(type.valueType, loopName + 'value_placeholder', true);
        cppBuffer += indentation + varName + '.insert(std::make_pair(' + loopName + 'key_placeholder, ' + loopName + 'value_placeholder));\n';
        if (getCompactType(type.keyType) === 'STRUCT') { cppBuffer += indentation + loopName + 'key_placeholder = ' + loopName + 'key_blank;\n'; }
        else if (['STRING', 'BINARY', 'LIST', 'SET', 'MAP'].includes(getCompactType(type.keyType))) { cppBuffer += indentation + loopName + 'key_placeholder.clear();\n'; }
        if (getCompactType(type.valueType) === 'STRUCT') { cppBuffer += indentation + loopName + 'value_placeholder = ' + loopName + 'value_blank;\n'; }
        else if (['STRING', 'BINARY', 'LIST', 'SET', 'MAP'].includes(getCompactType(type.valueType))) { cppBuffer += indentation + loopName + 'value_placeholder.clear();\n'; }
        DECREASE_INDENTATION();
        cppBuffer += indentation + '}\n';
    };

    // write exception functions
    const writeExceptionWriteResultFunctions = () => {
        // get exceptions
        if (ast.hasOwnProperty('exception')) {
            for (const exceptionName of Object.keys(ast.exception)) {
                // write name
                hBuffer += indentation + 'void ' + preposition + exceptionName + 'Function' + supposition + '(std::string& _buffer, ';
                cppBuffer += indentation + 'void ' + preposition + exceptionName + 'Function' + supposition + '(std::string& _buffer, ';
                // write field arguments
                hBuffer += exceptionName + '& _result, const char* _function_name);\n\n';
                cppBuffer += exceptionName + '& _result, const char* _function_name)\n';
                // finish declaration
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                // write begin
                cppBuffer += indentation + 'std::stack<uint16_t> _lastField;\n';
                cppBuffer += indentation + 'TCompactProtocol::writeMessageBegin(_buffer, _function_name, TMessageType::REPLY, 0);\n';
                cppBuffer += indentation + 'TCompactProtocol::writeStructBegin(_lastField);\n';
                // write exception
                writeWriteException(exceptionName, '_result', 1);
                // write end
                cppBuffer += indentation + 'TCompactProtocol::writeFieldStop(_buffer);\n';
                cppBuffer += indentation + '// TCompactProtocol::writeStructEnd(_lastField);\n';
                cppBuffer += indentation + '// TCompactProtocol::writeMessageEnd();\n';
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n\n';
            }
        }
    };
    const writeExceptionReadResultFunctions = () => {
        // get exceptions
        if (ast.hasOwnProperty('exception')) {
            for (const exceptionName of Object.keys(ast.exception)) {
                // write name
                hBuffer += indentation + 'void ' + preposition + exceptionName + 'Function' + supposition + '(char const*& _buffer, ';
                cppBuffer += indentation + 'void ' + preposition + exceptionName + 'Function' + supposition + '(char const*& _buffer, ';
                // write field arguments
                hBuffer += 'std::stack<uint16_t>& _lastField, std::optional<' + exceptionName + '>& e);\n\n';
                cppBuffer += 'std::stack<uint16_t>& _lastField, std::optional<' + exceptionName + '>& e)\n';
                // finish declaration
                cppBuffer += indentation + '{\n';
                INCREASE_INDENTATION();
                // variables
                cppBuffer += indentation + 'uint32_t _enum_placeholder;\n';
                cppBuffer += indentation + 'TCompactType _compactType_placeholder;\n';
                // give default value and read
                cppBuffer += indentation + 'e = ' + exceptionName + '{};\n';
                writeReadException(exceptionName, '(*e)');
                // end
                DECREASE_INDENTATION();
                cppBuffer += indentation + '}\n\n';
            }
        }
    };

    // write functions
    const writeWriteRequestFunctions = () => {
        // get functions
        if (ast.hasOwnProperty('service')) {
            for (const serviceName of Object.keys(ast.service)) {
                if (ast.service[serviceName].hasOwnProperty('functions')) {
                    for (const funcName of Object.keys(ast.service[serviceName].functions)) {
                        let func = ast.service[serviceName].functions[funcName];
                        // write name
                        hBuffer += indentation + 'void ' + preposition + func.name + supposition + '(std::string& _buffer, ';
                        cppBuffer += indentation + 'void ' + preposition + func.name + supposition + '(std::string& _buffer, ';
                        // write field arguments
                        for (const arg of func.args) {
                            let isPod = checkIsPodType(arg.type);
                            hBuffer += getCppType(arg.type) + (isPod ? ' ' : '& ') + arg.name + ', ';
                            cppBuffer += getCppType(arg.type) + (isPod ? ' ' : '& ') + arg.name + ', ';
                        }
                        // finish declaration
                        hBuffer = hBuffer.slice(0, -2) + ');\n\n';
                        cppBuffer = cppBuffer.slice(0, -2) + ')\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        // write message begin
                        cppBuffer += indentation + (func.args.length === 0 ? '// ' : '') + 'std::stack<uint16_t> _lastField;\n';
                        cppBuffer += indentation + 'TCompactProtocol::writeMessageBegin(_buffer, "' + func.name + '", ';
                        cppBuffer += func.oneway ? 'TMessageType::ONEWAY, 0);\n' : 'TMessageType::CALL, 0);\n';
                        cppBuffer += indentation + (func.args.length === 0 ? '// ' : '') + 'TCompactProtocol::writeStructBegin(_lastField);\n';
                        // write data
                        for (const field of func.args) { writeWriteType(field.type, field.name, field.id, false); }
                        // write message end
                        cppBuffer += indentation + 'TCompactProtocol::writeFieldStop(_buffer);\n';
                        cppBuffer += indentation + '// TCompactProtocol::writeStructEnd(_lastField);\n';
                        cppBuffer += indentation + '// TCompactProtocol::writeMessageEnd();\n';
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n\n';
                    }
                }
            }
        }
    };
    const writeWriteResultFunctions = () => {
        // get functions
        if (ast.hasOwnProperty('service')) {
            for (const serviceName of Object.keys(ast.service)) {
                if (ast.service[serviceName].hasOwnProperty('functions')) {
                    for (const funcName of Object.keys(ast.service[serviceName].functions)) {
                        let func = ast.service[serviceName].functions[funcName];
                        // oneway issues
                        if (func.oneway && (!options.generateResultForOneWay)) { continue; }
                        // write name
                        hBuffer += indentation + 'void ' + preposition + func.name + supposition + '(std::string& _buffer, ';
                        cppBuffer += indentation + 'void ' + preposition + func.name + supposition + '(std::string& _buffer, ';
                        // write field arguments
                        let isVoid = (func.type === 'void');
                        if (!isVoid) {
                            let isPod = checkIsPodType(func.type);
                            hBuffer += getCppType(func.type) + (isPod ? ' ' : '& ') + '_result, ';
                            cppBuffer += getCppType(func.type) + (isPod ? ' ' : '& ') + '_result, ';
                        }
                        // finish declaration
                        hBuffer = hBuffer.slice(0, -2) + ');\n\n';
                        cppBuffer = cppBuffer.slice(0, -2) + ')\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        // write message begin
                        cppBuffer += isVoid ? '' : indentation + 'std::stack<uint16_t> _lastField;\n';
                        cppBuffer += indentation + 'TCompactProtocol::writeMessageBegin(_buffer, "' + func.name + '", TMessageType::REPLY, 0);\n';
                        cppBuffer += isVoid ? '' : indentation + 'TCompactProtocol::writeStructBegin(_lastField);\n';
                        // write data
                        if (!isVoid) { writeWriteType(func.type, '_result', 0, false); }
                        // write message end
                        cppBuffer += indentation + 'TCompactProtocol::writeFieldStop(_buffer);\n';
                        cppBuffer += isVoid ? '' : indentation + '// TCompactProtocol::writeStructEnd(_lastField);\n';
                        cppBuffer += indentation + '// TCompactProtocol::writeMessageEnd();\n';
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n\n';
                    }
                }
            }
        }
    };
    const writeReadRequestFunctions = () => {
        // get functions
        if (ast.hasOwnProperty('service')) {
            for (const serviceName of Object.keys(ast.service)) {
                if (ast.service[serviceName].hasOwnProperty('functions')) {
                    for (const funcName of Object.keys(ast.service[serviceName].functions)) {
                        let func = ast.service[serviceName].functions[funcName];
                        // write name
                        let retValue = options.exceptions.thriftExceptionOnRead ? 'void ' : 'bool ';
                        hBuffer += indentation + retValue + preposition + func.name + supposition + '(char const*& _buffer, ';
                        cppBuffer += indentation + retValue + preposition + func.name + supposition + '(char const*& _buffer, ';
                        // write field arguments
                        for (const arg of func.args) {
                            hBuffer += getCppType(arg.type) + '& ' + arg.name + ', ';
                            cppBuffer += getCppType(arg.type) + '& ' + arg.name + ', ';
                        }
                        // finish declaration
                        hBuffer = hBuffer.slice(0, -2) + ');\n\n';
                        cppBuffer = cppBuffer.slice(0, -2) + ')\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        // message begin
                        cppBuffer += indentation + 'TMessageType _messageType;\n';
                        cppBuffer += indentation + 'if (_messageType == TMessageType::EXCEPTION) ';
                        if (options.exceptions.thriftExceptionOnRead) { cppBuffer += '{ throw std::runtime_error("TMessageType::EXCEPTION from ' + func.name + ' (read request)"); }\n'; }
                        else { cppBuffer += '{ return false; }\n'; }
                        // finish if no arguments
                        if (func.args.length === 0) {
                            cppBuffer += indentation + '// std::stack<uint16_t> _lastField;\n';
                            cppBuffer += indentation + '// TCompactProtocol::readStructBegin(_lastField);\n';
                            cppBuffer += indentation + '// ++_buffer; // readFieldStop\n';
                            cppBuffer += indentation + '// TCompactProtocol::readStructEnd(_lastField)\n';
                            cppBuffer += indentation + '// TCompactProtocol::readMessageEnd();\n';
                            if (!options.exceptions.thriftExceptionOnRead) { cppBuffer += indentation + 'return true;\n'; }
                            DECREASE_INDENTATION();
                            cppBuffer += indentation + '}\n\n';
                            continue;
                        }
                        // message begin with arguments and variables
                        cppBuffer += indentation + 'std::stack<uint16_t> _lastField;\n';
                        cppBuffer += indentation + 'uint32_t _enum_placeholder;\n';
                        cppBuffer += indentation + 'TCompactType _compactType_placeholder;\n';
                        cppBuffer += indentation + 'TCompactProtocol::readStructBegin(_lastField);\n';
                        if (options.exceptions.missingFunctionFieldsOnRead) { cppBuffer += indentation + 'uint_fast16_t function_field_count = 0;\n'; }
                        // while loop
                        cppBuffer += indentation + 'while (true)\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        // switch
                        cppBuffer += indentation + 'TCompactProtocol::readFieldBegin(_buffer, _lastField, _compactType_placeholder);\n';
                        cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::STOP) { break; }\n';
                        cppBuffer += indentation + 'switch (_lastField.top())\n';
                        cppBuffer += indentation + '{\n';
                        // cases
                        for (const field of func.args) {
                            cppBuffer += indentation + 'case ' + field.id + ':\n';
                            cppBuffer += indentation + '{\n';
                            INCREASE_INDENTATION();
                            if (options.checkFtypeOnRead) {
                                cppBuffer += indentation + 'if (_compactType_placeholder == TCompactType::' + getCompactType(field.type) + ')\n';
                                cppBuffer += indentation + '{\n';
                                INCREASE_INDENTATION();
                            }
                            writeReadType(field.type, field.name, false);
                            if (options.exceptions.missingFunctionFieldsOnRead) { cppBuffer += indentation + '++function_field_count;\n'; }
                            if (options.checkFtypeOnRead) {
                                DECREASE_INDENTATION();
                                cppBuffer += indentation + '}\n';
                                cppBuffer += indentation + 'else { TCompactProtocol::skip(_buffer, _compactType_placeholder, false); }\n'
                            }
                            cppBuffer += indentation + 'break;\n';
                            DECREASE_INDENTATION();
                            cppBuffer += indentation + '}\n';
                        }
                        // default case
                        cppBuffer += indentation + 'default:\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        cppBuffer += indentation + 'TCompactProtocol::skip(_buffer, _compactType_placeholder, false);\n';
                        cppBuffer += indentation + 'break;\n';
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n';
                        // end of switch and loop
                        cppBuffer += indentation + '}\n';
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n';
                        // check function fields were all there
                        if (options.exceptions.missingFunctionFieldsOnRead) {
                            cppBuffer += indentation + 'if (function_field_count != ' + func.args.length + ')\n';
                            cppBuffer += indentation + '{\n';
                            INCREASE_INDENTATION();
                            cppBuffer += indentation + 'std::string error_string = "Missing function fields (";\n';
                            cppBuffer += indentation + 'error_string += std::to_string(function_field_count);\n';
                            cppBuffer += indentation + 'error_string += "/' + func.args.length + ') read from ' + func.name + ' request";\n';
                            cppBuffer += indentation + 'throw std::runtime_error(error_string);\n';
                            DECREASE_INDENTATION();
                            cppBuffer += indentation + '}\n';
                        }
                        // end
                        cppBuffer += indentation + '// TCompactProtocol::readStructEnd(_lastField);\n';
                        cppBuffer += indentation + '// TCompactProtocol::readMessageEnd();\n';
                        if (!options.exceptions.thriftExceptionOnRead) { cppBuffer += indentation + 'return true;\n'; }
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n\n';
                    }
                }
            }
        }
    };
    const writeReadResultFunctions = () => {
        // get functions
        if (ast.hasOwnProperty('service')) {
            for (const serviceName of Object.keys(ast.service)) {
                if (ast.service[serviceName].hasOwnProperty('functions')) {
                    for (const funcName of Object.keys(ast.service[serviceName].functions)) {
                        let func = ast.service[serviceName].functions[funcName];
                        // oneway issues
                        if (func.oneway && (!options.generateResultForOneWay)) { continue; }
                        // write name
                        let retValue = options.exceptions.thriftExceptionOnRead ? 'void ' : 'bool ';
                        hBuffer += indentation + retValue + preposition + func.name + supposition + '(char const*& _buffer, ';
                        cppBuffer += indentation + retValue + preposition + func.name + supposition + '(char const*& _buffer, ';
                        // write field arguments
                        let isVoid = (func.type === 'void');
                        if (!isVoid) {
                            hBuffer += getCppType(func.type) + '& _result, ';
                            cppBuffer += getCppType(func.type) + '& _result, ';
                        }
                        let isThrows = (func.throws.length !== 0);
                        if (isThrows) {
                            hBuffer += 'std::optional<' + getCppType(func.throws[0].type) + '>& ' + func.throws[0].name + ', ';
                            cppBuffer += 'std::optional<' + getCppType(func.throws[0].type) + '>& ' + func.throws[0].name + ', ';
                        }
                        // finish declaration
                        hBuffer = hBuffer.slice(0, -2) + ');\n\n';
                        cppBuffer = cppBuffer.slice(0, -2) + ')\n';
                        cppBuffer += indentation + '{\n';
                        INCREASE_INDENTATION();
                        // message begin
                        cppBuffer += indentation + 'TMessageType _messageType;\n';
                        cppBuffer += indentation + 'TCompactProtocol::readMessageBegin(_buffer, _messageType);\n';
                        cppBuffer += indentation + 'if (_messageType == TMessageType::EXCEPTION) ';
                        if (options.exceptions.thriftExceptionOnRead) { cppBuffer += '{ throw std::runtime_error("TMessageType::EXCEPTION from ' + func.name + ' (read result)"); }\n'; }
                        else { cppBuffer += '{ return false; }\n'; }
                        cppBuffer += indentation + 'std::stack<uint16_t> _lastField;\n';
                        cppBuffer += indentation + 'uint32_t _enum_placeholder;\n';
                        cppBuffer += indentation + 'TCompactType _compactType_placeholder;\n';
                        cppBuffer += indentation + 'TCompactProtocol::readStructBegin(_lastField);\n';
                        cppBuffer += indentation + 'TCompactProtocol::readFieldBegin(_buffer, _lastField, _compactType_placeholder);\n';
                        // read both arg + throw
                        if (!isVoid && isThrows) {
                            // arg
                            cppBuffer += indentation + 'if ((_lastField.top() == 0)';
                            cppBuffer += options.checkFtypeOnRead ? ' && (_compactType_placeholder == TCompactType::' + getCompactType(func.type) + '))\n' : ')\n';
                            cppBuffer += indentation + '{\n';
                            INCREASE_INDENTATION();
                            writeReadType(func.type, '_result', false);
                            DECREASE_INDENTATION();
                            cppBuffer += indentation + '}\n';
                            // throw
                            cppBuffer += indentation + 'else if ((_lastField.top() == ' + func.throws[0].id + ')';
                            cppBuffer += options.checkFtypeOnRead ? ' && (_compactType_placeholder == TCompactType::' + getCompactType(func.throws[0].type) + ')) ' : ') ';
                            cppBuffer += indentation + '{ ' + preposition + func.throws[0].type + 'Function' + supposition;
                            cppBuffer += '(_buffer, _lastField, ' + func.throws[0].name + '); }\n';
                            // error
                            if (options.exceptions.missingFunctionFieldsOnRead) {
                                cppBuffer += indentation + 'else { throw std::runtime_error("Missing function field (0/1)"); }\n';
                            }
                        }
                        // read only arg
                        else if (!isVoid && !isThrows) {
                            // arg
                            cppBuffer += indentation + 'if ((_lastField.top() == 0)';
                            cppBuffer += options.checkFtypeOnRead ? ' && (_compactType_placeholder == TCompactType::' + getCompactType(func.type) + '))\n' : ')\n';
                            cppBuffer += indentation + '{\n';
                            INCREASE_INDENTATION();
                            writeReadType(func.type, '_result', false);
                            DECREASE_INDENTATION();
                            cppBuffer += indentation + '}\n';
                            // error
                            if (options.exceptions.missingFunctionFieldsOnRead) {
                                cppBuffer += indentation + 'else { throw std::runtime_error("Missing function field (0/1) read from result"); }\n';
                            }
                        }
                        // read only throw
                        else if (isVoid && isThrows) {
                            // throw
                            cppBuffer += indentation + 'if ((_lastField.top() == ' + func.throws[0].id + ')';
                            cppBuffer += options.checkFtypeOnRead ? ' && (_compactType_placeholder == TCompactType::' + getCompactType(func.throws[0].type) + ')) ' : ') ';
                            cppBuffer += indentation + '{ ' + preposition + func.throws[0].type + 'Function' + supposition;
                            cppBuffer += '(_buffer, _lastField, ' + func.throws[0].name + '); }\n';
                        }
                        // message end
                        cppBuffer += indentation + '// ++_buffer; // readFieldStop\n';
                        cppBuffer += indentation + '// TCompactProtocol::readStructEnd(_lastField);\n';
                        cppBuffer += indentation + '// TCompactProtocol::readMessageEnd();\n';
                        if (!options.exceptions.thriftExceptionOnRead) { cppBuffer += indentation + 'return true;\n'; }
                        DECREASE_INDENTATION();
                        cppBuffer += indentation + '}\n\n';
                    }
                }
            }
        }
    };

    // return
    const writeThrift = () => {
        // initial stuff
        getHeaderGuardName();
        writeHeaderGuardStart();
        writeIncludes();
        writeNamespaceStart();
        // enums, structs, and exceptions
        writeEnums();
        orderStructs();
        writeStructs();
        writeExceptionStructs();
        // read functions
        writeReadStart();
        writeRequestStart();
        writeReadRequestFunctions();
        writeRequestEnd();
        writeResultStart();
        writeExceptionReadResultFunctions();
        writeReadResultFunctions();
        writeResultEnd();
        writeReadEnd();
        // write functions
        writeWriteStart();
        writeRequestStart();
        writeWriteRequestFunctions();
        writeRequestEnd();
        writeResultStart();
        writeExceptionWriteResultFunctions();
        writeWriteResultFunctions();
        writeResultEnd();
        writeWriteEnd();
        // end
        writeNamespaceEnd();
        writeHeaderGuardEnd();
        return [hBuffer, cppBuffer];
    };
    return writeThrift();
};
