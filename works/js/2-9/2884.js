let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [H,M] = input[0].split(' ').map(Number) 
var time = (H * 60 + M) - 45 

var h = Math.floor(time / 60)
var m = Math.floor(time % 60) 
if(h < 0) h = 24 + h 
if(m < 0) m = 60 + m 
console.log(`${h} ${m}`)