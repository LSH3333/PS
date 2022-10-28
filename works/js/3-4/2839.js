let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = parseInt(input[0]) 
var ans = 10000 
for(i = 0; i < 2000; i++) {
    for(j = 0; j < 1001; j++) {
        var res = (3 * i) + (5 * j)
        if(res > N) break 
        if(res == N) {
            ans = Math.min(ans, i + j) 
        }
    }
}

if(ans == 10000) console.log(-1)
else console.log(ans)