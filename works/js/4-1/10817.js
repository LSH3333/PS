let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ').map(Number);
// let input = fs.readFileSync('input.txt').toString().split(' ').map(Number);

input.sort(function(a,b) {return a-b}) 
console.log(input[1])

