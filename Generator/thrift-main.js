let fs = require('fs');
let thriftText = fs.readFileSync("line.thrift").toString();
console.log(thriftText.length);

let thriftParser = require('./thrift-parser');
let thriftGenOptions = require('./thrift-gen-options');
let thriftGen = require('./thrift-gen.js');
let ast = thriftParser(thriftText);
let buffers = thriftGen(ast, thriftGenOptions.name, thriftGenOptions.protocolHeaderPath, thriftGenOptions);

fs.writeFileSync(thriftGenOptions.name + '.h', buffers[0]);
fs.writeFileSync(thriftGenOptions.name + '.cpp', buffers[1]);
