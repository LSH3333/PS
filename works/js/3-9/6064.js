let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let answer = ""
let t = parseInt(input[0])

for(tc = 1; tc <= t; tc++) {
    let [m,n,x,y] = input[tc].split(' ').map(Number) 
    let a = 0, b = 0, add = y-1, cnt = 1 

    while(cnt <= m * n) {
        if(a == x-1 && b == y-1) break 
        cnt += add 
        a = (a + add) % m 
        b = (b + add) % n 
        add = n 
    }
    let ans = cnt > m * n ? -1 : cnt 
    answer += `${ans}\n`
}

console.log(answer) 