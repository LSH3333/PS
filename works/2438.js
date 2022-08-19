let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var ans = "" 
for(i = 1; i <= N; i++) 
{
    var tmp = "" 
    for(j = 1; j <= i; j++) 
    {
        tmp += '*' 
    }
    ans += tmp + '\n' 
}
console.log(ans) 