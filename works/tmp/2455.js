let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var answer = 0 
var people = 0 
for(i = 0; i < 4; i++) 
{
    var [a, b] = input[i].split(' ').map(Number)
    people = people - a + b 
    answer = Math.max(answer, people) 
}
console.log(answer) 