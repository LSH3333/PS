const { reverse } = require('dns');
let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

var [A,B] = input[0].split(' ').map(Number)
var a = (A % 10 * 100) + (Math.floor(A % 100 / 10) * 10) + Math.floor(A / 100)
var b = (B % 10 * 100) + (Math.floor(B % 100 / 10) * 10) + Math.floor(B / 100)
if(a > b) console.log(a) 
else console.log(b)