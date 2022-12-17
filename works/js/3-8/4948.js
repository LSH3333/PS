let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let MAX = (123456 * 2) + 10
let primeNumber = Array(MAX) 
let answer = "" 

function FindPrimeNumber() {
    for(i = 2; i < MAX; i++) {
        primeNumber[i] = i 
    }
    for(i = 2; i*i < MAX; i++) {
        if(primeNumber[i] == 0) continue;
        for(j = i*i; j < MAX; j += i) {
            primeNumber[j] = 0 
        }
    }
}

FindPrimeNumber() 

for(tc = 0; tc < input.length-1; tc++) {
    let n = parseInt(input[tc]) 
    let cnt = 0 
    for(i = n+1; i <= 2*n; i++) {
        if(primeNumber[i] != 0) cnt++ 
    }
    answer += cnt + '\n' 
}

console.log(answer)