let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [gcd, lcm] = input[0].split(' ').map(Number)
let m = Math.floor(lcm / gcd) 
let a = 0, b = 0 

for(i = 1; i * i <= m; i++) {
    if(m % i != 0) continue
    if(GCD(i, Math.floor(m/i)) == 1) {
        a = i 
        b = Math.floor(m / i) 
    } 
}

console.log(a*gcd, b*gcd) 

function GCD(a, b) {
    if(b == 0) return a
    return GCD(b, a%b) 
}