let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n').map(Number);
// let input = fs.readFileSync('input.txt').toString().split('\n').map(Number)

var maxVal = 0, maxIdx = 0 
for(i = 0; i < input.length; i++) {
    if(input[i] > maxVal) {
        maxVal = input[i] 
        maxIdx = i+1 
    }
}
console.log(maxVal)
console.log(maxIdx)
