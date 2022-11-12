let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [w, h] = input[0].split(' ').map(Number)
var [x, y] = input[1].split(' ').map(Number)
var t = parseInt(input[2])

let X = ((t + x) % (2*w))
if(X >= w) X = w - X % w 
else X = X % w 

let Y = ((t + y) % (2*h)) 
if(Y >= h) Y = h - Y % h 
else Y = Y % h 

console.log(`${X} ${Y}`)