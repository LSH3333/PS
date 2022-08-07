let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [a, b, c] = input.map(Number)
var l = [Math.floor(a*b/c), Math.floor(a/b*c)] 
console.log(Math.max(l[0], l[1]))