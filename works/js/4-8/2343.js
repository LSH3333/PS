let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [N, M] = input[0].split(' ').map(Number) 
let answer = 1000000000
let arr = input[1].split(' ').map(Number) 

let left = 0, right = 1000000000
while(left <= right) {
    let mid = Math.floor(((left + right) / 2))
    
    let sum = 0, cnt = 0 
    let i = 0 
    while(i < N) {
        for(; i < N; i++) {
            sum += arr[i] 
            if(sum > mid) break 
        }
        sum = 0 
        cnt++
        if(cnt > M) break 
    }

    if(cnt <= M) {
        answer = Math.min(answer, mid) 
        right = mid - 1
    }
    else {
        left = mid + 1
    }
}

console.log(Math.floor(answer))



