let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [Br, Bc] = input[0].split(' ').map(Number) 
var [Dr, Dc] = input[1].split(' ').map(Number) 
var [Jr, Jc] = input[2].split(' ').map(Number) 

D = Math.abs(Dr - Jr) + Math.abs(Dc - Jc) 
B = Math.ceil(Math.abs(Br - Jr) + Math.abs(Bc - Jc) / 2)

if(D < B) console.log("daisy")
else if(D > B) console.log("bessie")
else console.log("tie")

