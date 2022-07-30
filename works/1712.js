let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

A = parseInt(input[0])
B = parseInt(input[1])
C = parseInt(input[2])
benefit = C- B 
if(benefit <= 0) console.log(-1) 
else console.log(Math.floor(A / benefit) + 1)


