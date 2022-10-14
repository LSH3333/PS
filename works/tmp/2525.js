let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

time = input[0].split(' ') 
h = parseInt(time[0]) 
m = parseInt(time[1])
cost = parseInt(input[1]) 

ends = h * 60 + m + cost 
h = (Math.floor(ends / 60)) % 24 
m = ends % 60 
console.log(h, m)


