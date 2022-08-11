let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [y1, m1, d1] = input[0].split(' ').map(Number)
var [y2, m2, d2] = input[1].split(' ').map(Number)

// 만 나이 
ans = y2 - y1 - 1 
if(m1 < m2 || (m1 == m2 && d1 <= d2)) console.log(ans+1) 
else console.log(ans) 
// 세는 나이 
ans = y2 - y1 + 1 
console.log(ans)
// 연 나이 
ans = y2 - y1 
console.log(ans)

