let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let a = parseInt(input[0]), b = parseInt(input[1]), c = parseInt(input[2]);
let d = parseInt(input[3]), e = parseInt(input[4])

let res1 = Math.min(a, Math.min(b,c))
let res2 = Math.min(d, e)
console.log(res1 + res2 - 50)