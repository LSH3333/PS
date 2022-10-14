let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0])
for(i = 1; i <= N; i++) 
{
    console.log(`Hello World, Judge ${i}!`)
}

