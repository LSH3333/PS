let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

d1 = parseInt(input[0])
d2 = parseInt(input[1])
pie = 3.141592 
ans = (pie * 2 * d2) + (d1 * 2) 
console.log(ans)

