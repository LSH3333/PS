let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var arr = input[0].split(' ').map(Number) 

var i = 1
while(true) {
    var cnt = 0 
    for(j = 0; j < arr.length; j++) {
        if(Math.floor(i % arr[j]) == 0) cnt++ 
    }

    if(cnt >= 3) break;
    i++
}

console.log(i) 

