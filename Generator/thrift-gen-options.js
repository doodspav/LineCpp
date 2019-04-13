let options = {};
// filename options
options.name = 'LINE'; // without extension
options.protocolHeaderPath = 'TCompactProtocol.h';
// default value for primitive thrift types and enums
// all enums are uint32_t and real values must be in positive range of i32
options.defaults = {
    'bool': 'false', // bool
    'byte': '0',     // uint8_t
    'i8': '0',       // uint8_t
    'i16': '0',      // uint16_t
    'i32': '0',      // uint32_t
    'i64': '0',      // uint64_t
    'double': '0.0f', // double
    'string': '',  // std::string (can also be a positive integer instead of a string)
    'enum_none_name': 'ENUM_NONE',
    'enum_none_value': Infinity  // can be any positive integer in the range 0-4294967295 or Infinity
};
// this will change the abstract syntax tree generated and mark all default struct fields as optional
options.treatDefaultAsOptional = true;
// default fields will still not be checked before write or after read
options.stdOptionalForDefault = true;
// generates writeResult and readResult for oneway functions
options.generateResultForOneWay = false;
// whether to check both fid and ftype or just fid on read
options.checkFtypeOnRead = true;
// whether to raise exception for things
options.exceptions = {
    'missingDefaultOnWrite': false,  // will access garbage data (UB) or default value if missing and is false
    'missingRequiredOnRead': true,  // variable will be set to default value if false
    'missingFunctionFieldsOnRead': true,  // variable will be set to default if false - also applies to return field
    'thriftExceptionOnRead': true  // function will return bool if set to false
};
// namespace rather than name extension for read/write and request/result
options.namespaces = {
    'readWrite': true,
    'requestResult': true
};

module.exports = options;
