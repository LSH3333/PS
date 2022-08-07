let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [A, B, C, D, P] = input.map(Number) 

X = A * P 
Y = P <= C ? B : B + D * (P - C) 
console.log(X < Y ? X : Y)