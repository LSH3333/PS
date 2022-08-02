let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

a = parseInt(input[0])
b = parseInt(input[1])
c = parseInt(input[2])

res = 0 
if(a == b && b == c) 
    res = 10000 + a * 1000 
else if(a == b && b != c) 
    res = 1000 + a * 100 
else if(b == c && c != a) 
    res = 1000 + b * 100 
else if(a == c && b != a) 
    res = 1000 + a * 100 
else 
    res = Math.max(a,b,c) * 100 

console.log(res) 
    

