let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [a, b, c] = input.map(Number) 
if(a + b + c >= 100) console.log("OK")
else 
{
    t = Math.min(a, b, c) 
    if(a == t) console.log("Soongsil")
    else if(b == t) console.log("Korea")
    else console.log("Hanyang")
}