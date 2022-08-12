let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [A,B,C,D,E] = input.map(Number) 
if(A < 0) ans = (C * Math.abs(A)) + D + (E * Math.abs(B)) 
else ans = (B - A) * E 
console.log(ans)


