let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var a = new Array(220) 
for(i = 0; i < N; i++) 
{
    a[i] = new Array(220).fill('*', 0, 220)
}

for(i = 0; i < N; i++) 
{
    a[i].fill(' ', 0, N-1-i) 
}

var ans = "" 
for(i = 0; i < N; i++) 
{
    for(j = 0; j < N+i; j++) 
    {
        ans += a[i][j] 
    }
    ans += '\n' 
}
console.log(ans)