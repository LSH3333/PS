let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var idx = 0 
var T = parseInt(input[idx++])
while(T--) {
    var sum = 0 
    var n = parseInt(input[idx++])
    var arr = input[idx++].split(' ').map(Number) 
    arr.forEach(number => sum += number) 
    console.log(sum)
}