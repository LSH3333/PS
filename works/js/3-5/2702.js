let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

function GCD(a, b) {
    if(b == 0) return a 
    return GCD(b, Math.floor(a%b))
}

var T = parseInt(input[0])
for(t = 1; t <= T; t++) {
    var [a,b] = input[t].split(' ').map(Number) 
    var gcd = GCD(a,b)  
    // a * b = lcm(a,b) * gcd(a,b) 
    var lcm = Math.floor((a * b) / gcd) 
    console.log(lcm, gcd) 
}