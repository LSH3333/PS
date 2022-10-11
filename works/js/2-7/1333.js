let fs = require('fs');
// let input = fs.readFileSync(0).toString().trim().split('\n').map(Number);
// let input = fs.readFileSync('input.txt').toString().split(' ').map(Number);

var [N, L, D] = fs.readFileSync(0).toString().trim().split(' ').map(Number);
// var [N, L, D] = fs.readFileSync('input.txt').toString().split(' ').map(Number)
var arr = new Array(10000)
var idx = 0 
for(i = 0; i < N; i++) {    
    for(j = 0; j < L; j++) {
        arr[idx++] = true 
    }
    idx += 5 
}

var t = 0 
while(true) {
    if(t > (L+5) * N) {
        console.log(t)
        break;
    }

    if(arr[t] != true) {
        console.log(t) 
        break 
    }
    t += D 
}