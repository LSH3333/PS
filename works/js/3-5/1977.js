let fs = require('fs');

var [M, N] = fs.readFileSync(0).toString().trim().split('\n').map(Number)
// var [M, N] = fs.readFileSync('input.txt').toString().split('\n').map(Number)

var sum = 0 
var minVal = 100000
for(i = 1; i <= 100; i++) {
    var n = i * i 
    if(n >= M && n <= N) {
        sum += n 
        minVal = Math.min(minVal, n) 
    }
}

if(sum == 0) {
    console.log(-1)
}
else {
    console.log(sum)
    console.log(minVal)    
}
