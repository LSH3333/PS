let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0])
var add = 5 
var n = 1, cnt = 1 
while(true) {
    if(n >= N) {
        console.log(cnt) 
        break
    } 
    cnt++ 
    n = n + 1 + add
    add += 6    
}