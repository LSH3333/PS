let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [x,y,w,h] = input[0].split(' ').map(Number) 
var ans = Math.min(x, y, w-x, h-y)
console.log(ans)