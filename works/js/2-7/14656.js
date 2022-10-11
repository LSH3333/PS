let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var n = parseInt(input[0]) 
var ans = 0 
var arr = input[1].split(' ').map(Number) 
for(i = 1; i <= n; i++) {
    if(arr[i-1] != i) ans++
}
console.log(ans) 