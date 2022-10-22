let fs = require('fs');
const { parse } = require('path/posix');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = input[0] 
var n = N 
if(N.length < 2) N = '0' + N 
var ans = 0 

while(true) {
    ans++     
    if(n.length < 2) {
        n = '0' + n 
    }
    var sum = (parseInt(n[0]) + parseInt(n[1])).toString() 
    if(sum.length < 2) {
        sum = '0' + sum 
    }
    n = n[1] + sum[1]
    if(n == N) break
}
console.log(ans) 

 

