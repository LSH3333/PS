let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0]) 
let ans = 0 

for(let i = 1; i <= N; i++) {
    let n = i.toString() 
    if(i < 10) {
        ans++
    }
    else {
        let sub = parseInt(n[0]) - parseInt(n[1])
        let check = true 
        for(j = 1; j < n.length-1; j++) {
            if(parseInt(n[j]) - parseInt(n[j+1]) != sub) {
                check = false 
                break 
            }
        }
        if(check) ans++ 
    }
}

console.log(ans)

