let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n').map(Number);
// let input = fs.readFileSync('input.txt').toString().split('\n').map(Number);

var total = input[0] 
var sum = 0 
for(i = 1; i < 10; i++) {
    sum += input[i] 
}
console.log(total - sum) 