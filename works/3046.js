let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');
v = input[0].split(' ').map(x => parseInt(x)) 
console.log((v[1]*2)-v[0])

