let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [L, A, B, C, D] = input.map(Number) 

a = A % C == 0 ? A / C : Math.floor(A / C) + 1
b = B % D == 0 ? B / D : Math.floor(B / D) + 1 
ans = a < b ? L - b : L - a 
console.log(ans)