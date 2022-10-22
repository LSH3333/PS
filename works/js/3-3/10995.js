let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var ans = ''

for(i = 1; i <= N; i++) {
    if(i % 2 == 0) {
        ans += ' '
    }
    for(j = 1; j <= N; j++) {
        if(j == N) ans += '*\n'
        else ans += '* '
    }
}

console.log(ans) 