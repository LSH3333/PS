let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let n = parseInt(input[0])
ans = 0;
for(i = 1; i <= n; i++) ans += i 
console.log(ans)

