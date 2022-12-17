let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [x1,y1] = input[0].split(' ').map(Number) 
var [x2,y2] = input[1].split(' ').map(Number) 
var [x3,y3] = input[2].split(' ').map(Number) 

var a = x1*y2 + x2*y3 + x3*y1
var b = x2*y1 + x3*y2 + x1*y3
var cal = a - b

if(cal == 0) console.log(0) 
else if(cal > 0) console.log(1) 
else console.log(-1) 