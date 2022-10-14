let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('/');
// let input = fs.readFileSync('input.txt').toString().split('/');

var [K, D, A] = input.map(Number) 
if(K + A < D || D == 0) console.log("hasu")
else console.log("gosu")


