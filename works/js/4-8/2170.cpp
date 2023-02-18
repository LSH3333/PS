let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0]) 
let answer = 0
let v = new Array() 
for(i = 1; i <= N; i++) {
    let ip = input[i].split(' ').map(Number) 
    v.push([ip[0], ip[1]])
}

// first 기준 오름차순 정렬 
v.sort(function(a, b) {
    return a[0] - b[0]
})

let begin = v[0][0], end = v[0][1] 
for(i = 1; i < v.length; i++) {
    let x = v[i][0], y = v[i][1] 
    if(x <= end) {
        end = Math.max(y, end) 
    }
    else {
        answer += (end - begin) 
        begin = x 
        end = y 
    }
}

answer += (end - begin) 
console.log(answer) 

