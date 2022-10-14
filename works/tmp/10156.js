let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

K = parseInt(input[0]) // 과자 한개 가격 
N = parseInt(input[1]) // 사려고하는 과자 갯수 
M = parseInt(input[2]) // 가진 돈 
res = M - (K*N)
if(res < 0) res *= -1
else res = 0
console.log(res)


