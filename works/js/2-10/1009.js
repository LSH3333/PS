let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var T = parseInt(input[0])
for(t = 1; t < input.length; t++) {
    var [a,b] = input[t].split(' ').map(Number) 
    
    var res = 1 
    for(i = 0; i < b; i++) {
        res = (res * a) % 10    
    }

    if(res == 0) res = 10
    console.log(res)
}