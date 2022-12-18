let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [A,B,C] = input[0].split(' ').map(BigInt) 
console.log(dfs(A,B,C).toString())


function dfs(a, b, c) {
    a = BigInt(a), b = BigInt(b), c = BigInt(c)
    if(b == 1) {
        return BigInt(a % c )
    }
    
    let n = dfs(a, b/2n, c) 
    if(b % 2n == 0) {
        return BigInt((n * n) % c ) 
    }
    else {
        return BigInt((((n * n) % c) * a) % c) 
    }
}
