let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [S,T,D] = input.map(Number) 
time = Math.floor((D / (S * 2)))
F = time * T 
console.log(F)
