let fs = require('fs');
// let input = fs.readFileSync(0).toString().trim().split('\n').map(Number)
// let input = fs.readFileSync('input.txt').toString().split('\n').map(Number)

let mark = new Array(10001)
for(i = 0; i < mark.length; i++) {
    mark[i] = false 
}


for(let i = 1; i <= 10000; i++) {
    let n = i.toString() 
    while(true) {
        let next = parseInt(n) 
        for(j = 0; j < n.length; j++) {
            next += parseInt(n[j]) 
        }        
        n = parseInt(next) 
        if(n > 10000) break 
        mark[n] = true 
        n = n.toString() 
    }
}

var ans = "" 
for(i = 1; i <= 10000; i++) {
    if(!mark[i]) {
        ans += i + '\n'
    }
}
console.log(ans)