let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')


let [N, S] = input[0].split(' ').map(Number) 
let arr = input[1].split(' ').map(Number) 
let answer = 200000

let left = 0, right = 0, sum = arr[0] 
while(left <= right && right < N) {
    if(sum >= S) {
        answer = Math.min(answer, right-left+1)
        sum -= arr[left++]
    }
    else {
        sum += arr[++right]
    }
}

if(answer == 200000) console.log(0)
else console.log(answer)
