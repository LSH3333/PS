let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

// let arr = new Array(1200).fill(0).map(() => new Array(2400).fill(' '))
let N = parseInt(input[0])
let K = parseInt(input[1])

let left = 1, right = N * N 
while(left <= right) {
    let mid = Math.floor((left + right) / 2) 

    let cnt = Count(mid) 

    if(cnt < K) {
        left = mid + 1
    }
    else {
        right = mid - 1
        answer = mid 
    }
}

console.log(answer) 


function Count(mid) {
    let cnt = 0 

    for(i = 1; i <= N; i++) {
        if(i * N <= mid) {
            cnt += N 
        }
        else {
            cnt += Math.floor(mid / i) 
        }
    }

    return cnt 
}

