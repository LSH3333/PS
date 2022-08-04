let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');
v = input[0].split(' ').map(x => parseInt(x)*parseInt(x)) 

ans = 0 
for(i = 0; i < v.length; i++) ans += v[i]
console.log(ans%10)
