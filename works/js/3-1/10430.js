let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [A,B,C] = input[0].split(' ').map(Number) 

console.log(Math.floor((A+B)%C))
console.log(Math.floor((Math.floor(A%C) + Math.floor(B%C))%C)) 
console.log(Math.floor(Math.floor((A*B)%C)))
console.log(Math.floor((Math.floor(A%C) * Math.floor(B%C))%C))

