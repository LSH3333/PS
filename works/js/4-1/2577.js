let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let a = parseInt(input[0]), b = parseInt(input[1]), c = parseInt(input[2])
let res = a * b * c 
let res_s = res.toString()
let mark = Array(10).fill(0)
let answer = ""

for(i = 0; i < res_s.length; i++) {
    mark[parseInt(res_s[i])]++ 
}

for(i = 0; i < 10; i++) {
    answer += mark[i] + '\n'
}

console.log(answer) 