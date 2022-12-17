let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [n, m] = input[0].split(' ')
while(n.length != m.length) {
    n = "0" + n 
}

let cnt = 0
let _n = n, _m = m 

for(i = n.length-1; i >= 0; i--) {
    if(n[i] == '8' && m[i] == '8') {    
        n = n.substr(0, i) + '9' + n.substr(i+1)
        if(n > m) { cnt++ } 
        else { n = _n; m = _m; }
    }
}

console.log(cnt) 