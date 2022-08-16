let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

for(i = 0; i < input.length-1; i++)  
{
    var [A, B] = input[i].split(' ').map(Number) 
    console.log(A+B)
}




