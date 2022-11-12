let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let K = parseInt(input[0])
let C = parseInt(input[1])
let ans = "" 
for(i = 2; i < 2+C; i++) {
    var [M, N] = input[i].split(' ').map(Number) 
    if(M == N) {
        ans += "1\n" 
        continue 
    }

    let left = K - Math.max(M, N) 
    if(M > N) {
        if(Math.abs(M-N) - left <= 2) {
            ans += "1\n"
        }   
        else {
            ans += "0\n"
        }
    }
    else { // M < N 
        if(Math.abs(M-N) - left <= 1) {
            ans += "1\n"
        }
        else {
            ans += "0\n"
        }
    }
}
console.log(ans)