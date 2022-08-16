let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var T = parseInt(input[0])
for(i = 1; i <= T; i++) 
{
    var [A, B] = input[i].split(' ').map(Number)     
    console.log(`Case #${i}: ${A+B}`)   
}



