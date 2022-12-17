let fs = require('fs');
const internal = require('stream');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

let cord = new Array(10001) 
for(i = 0; i < cord.length; i++) cord[i] = new Array(2) 
let sum = 0 
let n = parseInt(input[0])
for(i = 1; i <= n; i++) {
    let [a,b] = input[i].split(' ').map(Number) 
    cord[i-1][0] = a 
    cord[i-1][1] = b 
}

for(i = 1; i < n-1; i++) {
    sum += CCW(cord[0][0], cord[0][1], cord[i][0], cord[i][1], cord[i+1][0], cord[i+1][1])
}

console.log(Math.abs(sum).toFixed(1))


function CCW(x1, y1, x2, y2, x3, y3) {
    let a = x1*y2 + x2*y3 + x3*y1;
    let b = x2*y1 + x3*y2 + x1*y3;
    return (a-b) / 2
}