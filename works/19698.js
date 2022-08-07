let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [N, W, H, L] = input.map(Number) 
w = Math.floor(W / L)
h = Math.floor(H / L)
ans = w*h
console.log(ans < N ? ans : N)

