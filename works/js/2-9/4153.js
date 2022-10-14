let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

for(t = 0; t < input.length-1; t++) {
    var arr = input[t].split(' ').map(Number) 
    arr.sort((a,b) => (a-b)) 
    
    if((arr[0]*arr[0]) + (arr[1]*arr[1]) == (arr[2]*arr[2])) {
        console.log("right")
    }
    else {
        console.log("wrong")
    }
}