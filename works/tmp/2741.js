let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0])
var ans = "" 
for(i = 1; i <= N; i++) 
{
    ans += i + '\n'  
}
console.log(ans)

