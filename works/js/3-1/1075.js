let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var F = parseInt(input[1]) 

var num = N - N % 100 
var ans = 0;
if(Math.floor(num % F == 0)) {
    ans = Math.floor(num / F) * F 
}
else {
    ans = Math.floor(num / F) * F + F
}

ans = ans % 100 
if(ans < 10) console.log(`0${ans}`)
else console.log(ans)