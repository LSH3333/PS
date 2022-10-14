let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [c, d] = input.map(Number)

if(c < d || (c+d) % 2 != 0 || (c-d) % 2 != 0) 
    console.log(-1)
else 
{
    var a = (c + d) / 2 
    var b = (c - d) / 2
    console.log(a, b)
}
