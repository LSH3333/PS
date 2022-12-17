let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let n = parseInt(input[0])
let len = 1, val = n, cnt = 0, num = 1 

while(val > 0) {
    if(Math.floor(val / 10) == 0) {
        cnt += (n - len + 1) * num 
        break 
    }
    else {
        cnt += 9 * len * num 
        len *= 10 
        num++ 
        val = Math.floor(val / 10) 
    }
}

console.log(cnt) 
