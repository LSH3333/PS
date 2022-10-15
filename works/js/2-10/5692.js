let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var fac = Array(10) 
fac[0] = 1
for(i = 1; i < 10; i++) {
    fac[i] = fac[i-1] * i 
}

var answer = "" 

for(t = 0; t < input.length-1; t++) {
    var N = input[t]
    var ans = 0 
    for(i = 0; i < N.length; i++) {
        ans += parseInt(N[i]) * fac[N.length-i] 
    }   

    answer += ans.toString() + '\n'
}
console.log(answer)