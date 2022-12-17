let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

function Cal(n, div) {
    let cnt = 0 
    while(n > 0) {
        n = Math.floor(n / div) 
        cnt += n 
    }
    return cnt 
}

let [n, m] = input[0].split(' ').map(Number) 
let a = Cal(n,2) - (Cal(m,2) + Cal(n-m,2));
let b = Cal(n, 5) - (Cal(m,5) + Cal(n-m, 5));
console.log(Math.min(a,b))

  