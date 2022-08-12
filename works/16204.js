let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');

var [N, M, K] = input.map(Number) 

var O1 = M, X1 = N-M 
var O2 = K, X2 = N-K 

var ans = Math.min(O1, O2) + Math.min(X1, X2) 
console.log(ans)


