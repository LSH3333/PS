let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

A = parseInt(input[0])
B = parseInt(input[1])
C = 0
if(A > B) C = A - B 
else C = B - A 
console.log(C)

