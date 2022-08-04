let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

cnt = 0
N = input[0]
list = input[1].split(' ').forEach((cur, idx, arr) => 
{
    if(cur == N) cnt++
})
console.log(cnt)

