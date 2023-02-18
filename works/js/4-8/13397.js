let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [N, M] = input[0].split(' ').map(Number) 
let arr = input[1].split(' ').map(Number) 
let answer = 100000

let left = 0, right = 10000 
while(left <= right) {
    let mid = Math.floor((left+right)/2)

    let cnt = 1
    let minVal = 100000, maxVal = 0 
    for(i = 0; i < N; i++) {
        minVal = Math.min(minVal, arr[i]) 
        maxVal = Math.max(maxVal, arr[i])

        if(maxVal - minVal > mid) {
            cnt++ 
            minVal = arr[i], maxVal = arr[i] 
        }
    }

    if(cnt > M) {
        left = mid + 1
    }
    else {
        right = mid - 1
        answer = Math.min(answer, mid) 
    }
}

console.log(answer) 