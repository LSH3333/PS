let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = parseInt(input[0])
var arr = input[1].split(' ').map(Number) 

var ans = 0 
var h = 0 
for(i = 1; i < arr.length; i++) {
    if(arr[i-1] < arr[i]) {
        h += arr[i] - arr[i-1]
        ans = Math.max(ans, h) 
    }
    else {
        h = 0 
    }
}
console.log(ans) 
