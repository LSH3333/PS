let fs = require('fs');
var [M, N] = fs.readFileSync(0).toString().trim().split('\n').map(Number)
// var [M, N] = fs.readFileSync('input.txt').toString().split('\n').map(Number)

var arr = new Array(N+1)
arr[1] = 0
for(i = 2; i <= N; i++) {
    arr[i] = i 
}
for(i = 2; i*i <= N; i++) {
    if(arr[i] == 0) continue 
    for(j = i * i; j <= N; j+=i) {
        arr[j] = 0 
    }    
}

var sum = 0, minVal = 100000 
for(i = M; i <= N; i++) {
    if(arr[i] != 0) {
        sum += i 
        minVal = Math.min(minVal, i) 
    }
}

if(sum == 0) {
    console.log(-1) 
}
else {
    console.log(sum) 
    console.log(minVal)
}
