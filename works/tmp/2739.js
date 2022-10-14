let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0])
for(i = 1; i <= 9; i++) 
{
    console.log(`${N} * ${i} = ${N*i}`)
}
