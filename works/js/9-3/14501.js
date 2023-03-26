let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let answer = 0 
let N = parseInt(input[0]) 
let T = new Array(N+1).fill(0) 
let P = new Array(N+1).fill(0) 
for(let i = 1; i < input.length; i++) {
    let [t,p] = input[i].split(' ').map(Number) 
    T[i] = t 
    P[i] = p 
}

solve(1, 0) 
console.log(answer) 


function solve(cur_day, total_money) {
    if(cur_day >= N+1) {
        answer = Math.max(answer, total_money) 
        return 
    }

    if(cur_day + T[cur_day] <= N+1) {
        solve(cur_day + T[cur_day], total_money + P[cur_day])
    }
    if(cur_day+1 <= N+1) {
        solve(cur_day+1, total_money)
    }
}