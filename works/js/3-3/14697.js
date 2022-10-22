let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [A,B,C,N] = input[0].split(' ').map(Number)
var ans = false 

for(i = 0; i < 100; i++) {
    for(j = 0; j < 100; j++) {
        for(k = 0; k < 100; k++) {
            var sum = (A * i) + (B * j) + (C * k) 
            if(sum == N) {
                ans = true; break; 
            }
            else if(sum > N) {
                break; 
            }
        }
    }
}

if(ans) console.log(1)
else console.log(0) 