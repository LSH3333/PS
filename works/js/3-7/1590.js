let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [N, T] = input[0].split(' ').map(Number)
var ans = Math.pow(2,31) 
for(i = 1; i <= N; i++) {
    var [start, len, cnt] = input[i].split(' ').map(Number) 
    for(j = 0; j < cnt; j++) {
        var time = start + (j * len) 
        if(time - T >= 0) {
            ans = Math.min(ans, time-T)
            break
        }
    }
}

if(ans == 2147483648) console.log(-1)
else console.log(ans)