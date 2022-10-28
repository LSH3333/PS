let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0])
var score = input[1].split(' ').map(Number) 

var M = 0 
var sum = 0
score.forEach(i => M = Math.max(M, i))

for(i = 0; i < score.length; i++) {
    score[i] = score[i] / M * 100 
    sum += score[i] 
}

console.log(sum / score.length)
