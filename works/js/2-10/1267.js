let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var arr = input[1].split(' ').map(Number) 
var ySum = 0, mSum = 0 

for(time of arr) {
    ySum += (Math.floor(time / 30) + 1) * 10 
    mSum += (Math.floor(time / 60) + 1) * 15
}

if(ySum < mSum) {
    console.log(`Y ${ySum}`)
}
else if(ySum > mSum) {
    console.log(`M ${mSum}`)
}
else {
    console.log(`Y M ${ySum}`)
}