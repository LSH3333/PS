let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

A = parseFloat(input[0])
B = parseFloat(input[1])
console.log(A/B)
