let fs = require('fs');
// let input = fs.readFileSync('input.txt').toString().split('\n');
let input = fs.readFileSync(0).toString().trim().split('\n');

var [C, K, P] = input[0].split(' ').map(Number)
var ans = 0 
for(i = 1; i <= C; i++) {
    ans += (K * i) + (P * i * i)
}
console.log(ans) 