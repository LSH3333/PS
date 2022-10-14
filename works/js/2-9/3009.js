let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [x1,y1] = input[0].split(' ').map(Number) 
var [x2,y2] = input[1].split(' ').map(Number) 
var [x3,y3] = input[2].split(' ').map(Number) 

var x = 0, y = 0 
if(x1 == x2) x = x3 
else if(x2 == x3) x = x1 
else x = x2 

if(y1 == y2) y = y3 
else if(y2 == y3) y = y1 
else y = y2 

console.log(x,y)