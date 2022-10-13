let fs = require('fs');
// let input = fs.readFileSync('input.txt').toString().split('\n');
let input = fs.readFileSync(0).toString().trim().split('\n');

var T = parseInt(input[0])
for(i = 1; i <= T; i++) {
    var [C,R,N] = input[i].split(' ').map(Number) 

    var r, c 
    if(N % C == 0) {
        r = Math.floor(N / C) 
        c = C 
    }
    else {
        r = Math.floor(N / C) + 1 
        c = Math.floor(N % C) 
    }

    var ans = c.toString() 
    if(r < 10) ans = ans + '0' + r.toString() 
    else ans = ans + r.toString()

    console.log(ans)
}