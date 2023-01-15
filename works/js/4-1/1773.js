let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [n,c] = input[0].split(' ').map(Number)
let mark = Array(2000010).fill(false)

for(i = 1; i <= n; i++) {
    let num = parseInt(input[i])
    for(j = num; j <= c; j+=num) mark[j] = true;
}

let cnt = 0
for(i = 0; i <= c; i++) {
    if(mark[i]) cnt++ 
}

console.log(cnt)
