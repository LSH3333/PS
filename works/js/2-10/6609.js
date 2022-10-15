let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

for(t = 0; t < input.length; t++) {
    var [M, P, L, E, R, S, N] = input[t].split(' ').map(Number) 

    var e = E, l = L, p = P, m = M     
    while(N--) {        
        var ne = (m * E)
        var nl = ne          
        var np = Math.floor(l / R)     
        var nm = Math.floor(p / S)      

        e = ne; p = np; m = nm; l = nl;
    }
    console.log(m)
}