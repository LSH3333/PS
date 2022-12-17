let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let finger = parseInt(input[0])
let num = parseInt(input[1])
let ans = 0, goAndReturn = 0 

if(finger == 1) {
    goAndReturn = num - 1
    ans = 1 + (8 * goAndReturn) 
    ans += 7 
}
else if(finger == 5) {
    goAndReturn = num 
    ans = 1 + (8 * goAndReturn) 
    ans += 3 
}
else {
    goAndReturn = Math.floor(num / 2)
    ans = 1 + (8 * goAndReturn) 
    if(num % 2 == 0) {
        ans += finger - 2
    }
    else {
        ans += 7 - finger + 1
    }
}
console.log(ans) 
