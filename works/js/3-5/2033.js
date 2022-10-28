let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = parseInt(input[0])
var n = 10 
while(n <= N) {
    if(N > n) {
        // 반올림 
        if(Math.floor(N % n) / (n / 10) >= 5) {
            N = (Math.floor(N / n) + 1) * n 
        }
        else {
            N = Math.floor(N / n) * n 
        }
    }
    
    n *= 10 
}
console.log(N)

