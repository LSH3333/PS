let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [N, M] = input.map(Number)

ans = "" 
if(M == 1 || M == 2) ans = "NEWBIE!"
else if(M <= N) ans = "OLDBIE!"
else ans = "TLE!"

console.log(ans)


