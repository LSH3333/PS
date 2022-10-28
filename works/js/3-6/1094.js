let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = parseInt(input[0])
var ans = 0 
while(N > 0) {
    if(N % 2 != 0) ans++ 
    N = Math.floor(N / 2)
}
console.log(ans)

