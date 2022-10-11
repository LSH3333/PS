let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var sum = 0 
var min = 1000000
for(i = 0; i < input.length; i++) {
    var val = parseInt(input[i])    
    if(val % 2 != 0) {
        sum += val 
        if(val < min) min = val 
    }
}

if(sum == 0) {
    console.log(-1)
}
else {
    console.log(sum)
    console.log(min)
}
