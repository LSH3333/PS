let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [x,y,c] = input[0].split(' ').map(Number) 
let left = 0.0, right = Math.min(x, y) 

for(i = 0; i < 10000; i++) {
    let d = (left + right) / 2 
    let h1 = Math.sqrt(x * x - d * d) 
    let h2 = Math.sqrt(y * y - d * d) 
    let h = (h1 * h2) / (h1 + h2) 

    if(h > c) left = d 
    else right = d 
}

console.log(left.toFixed(3))