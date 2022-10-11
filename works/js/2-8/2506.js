let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var n = parseInt(input[0])
var arr = input[1].split(' ').map(Number) 
var ans = 0, sc = 1  
for(i = 0; i < n; i++) {
    if(arr[i] == 1) {
        ans += sc 
        sc++
    }
    else {
        sc = 1 
    }
}
console.log(ans)