let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')


let N = parseInt(input[0])
let arr = input[1].split(' ').map(Number) 

let mark = new Array(N+1).fill(false) 
for(let i = 0; i < N; i++) {
    mark[arr[i]] = true 
}

let i = 0
for(i = N-1; i >= 0; i--) {
    let n = arr[i]
    mark[n] = false 

    let found = false 

    for(let j = n+1; j <= N; j++) {
        if(mark[j]) continue 
        mark[j] = true 
        arr[i] = j 
        found = true 
        break 
    }
    if(found) break 
}

i++
while(i < N) {
    for(let j = 1; j <= N; j++) {
        if(mark[j]) continue 
        mark[j] = true 
        arr[i] = j 
        break 
    }
    i++ 
}

// 다음 순열이 오름차순 정렬된 상태면 -1 출력 
let sorted = true  
for(i = 0; i < N-1; i++) {
    if(arr[i] > arr[i+1]) {
        sorted = false 
        break 
    }
}

if(sorted) {
    console.log(-1)
}
else {
    let answer = ""
    arr.map((i) => answer += i + " ") 
    console.log(answer) 
}

