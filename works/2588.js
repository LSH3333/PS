let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

A = parseInt(input[0])
B = parseInt(input[1])

console.log(A * (B % 10))
console.log(A * Math.floor(B/10%10))
console.log(A * Math.floor(B/100))
console.log(A*B)