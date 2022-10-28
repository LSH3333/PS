let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var [A,B] = input[0].split(' ').map(Number) 
var ans = 0 
var i = 1, cnt = 0 

while(cnt < B) {
    for(j = 0; j < i; j++) {
        cnt++ 
        if(cnt >= A && cnt <= B) ans += i 
    }
    i++ 
}

console.log(ans)