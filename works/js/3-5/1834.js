let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = BigInt(input[0])
var ans = BigInt(0)
var i = BigInt(1) 
for(; i < N; i++) {
    ans += (N * i) + i 
}
console.log(`${ans}`)
