let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let MAX = 1000001
let primeNumber = Array(MAX) 
let answer = "" 

function FindPrimeNumber() {
    primeNumber[1] = 0 
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
    let a = -1, b = -1 
    
    for(i = 1; i < n; i += 2) {
        if(primeNumber[i] != 0 && primeNumber[n-i] != 0) {
            a = i 
            b = n-i 
            break 
        }
    }

    if(a == -1 && b == -1) {
        answer += "Goldbach's conjecture is wrong.\n"
    }
    else {
        answer += n + " = " + a + " + " + b + "\n"
    }
}

console.log(answer)