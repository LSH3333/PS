let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var r = 2, c = 0 
var upward = true 
while(N--) {
    if(upward) {
        nr = r - 1
        nc = c + 1
        if(nr < 1) {
            upward = false 
            nr = nr + 1           
        }        
    }

    else {
        nr = r + 1 
        nc = c - 1
        if(nc < 1) {
            upward = true 
            nc = nc + 1
        }
    }
    r = nr 
    c = nc 
}

console.log(`${r}/${c}`)