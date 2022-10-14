let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');


var [x, y] = input.map(Number)
if(x > 0 && y > 0) console.log(1) 
else if(x < 0 && y > 0) console.log(2) 
else if(x < 0 && y < 0) console.log(3) 
else console.log(4)