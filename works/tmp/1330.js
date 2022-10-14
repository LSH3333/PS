let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

A = parseInt(input[0])
B = parseInt(input[1])
ans = ""
if(A > B) ans = ">"
else if(A < B) ans = "<"
else ans = "=="
console.log(ans)


