let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

A = parseInt(input[0])
grade = "A"
if(A <= 89) grade = "B"
if(A <= 79) grade = "C"
if(A <= 69) grade = "D"
if(A <= 59) grade = "F"
console.log(grade)