let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0])
let arr = new Array() 
for(i = 1; i <= N; i++) {
    arr.push([parseInt(input[i]), i-1])
}

arr.sort((a,b) => {
    return a[0] - b[0]
})

let answer = 0 
for(i = 0; i < N; i++) {
    answer = Math.max(answer, arr[i][1] - i + 1)
}

console.log(answer)
