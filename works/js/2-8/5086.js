let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

for(t = 0; t < input.length-1; t++) {
    var [a,b] = input[t].split(' ').map(Number) 
    if(b % a == 0) console.log("factor")    
    else if(a % b == 0) console.log("multiple")
    else console.log("neither")
}