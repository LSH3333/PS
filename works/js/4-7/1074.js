let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [N, goalR, goalC] = input[0].split(' ').map(Number)
console.log(dfs(N, 0, 0, 0)) 



function dfs(n, startNum, startR, startC) {
    if(n == 0) return startNum 

    let length = Math.pow(2, n) 
    let cnt = Math.floor(length / 2) * (length / 2) 
    let area = FindArea(length, startR, startC) 

    if(area == 0) {
        return dfs(n-1, startNum + (cnt * area), startR, startC)
    }
    else if(area == 1)
    {
        return dfs(n-1, startNum + (cnt * area), startR, startC + Math.floor(length / 2))
    }
    else if(area == 2)
    {
        return dfs(n-1, startNum + (cnt * area), startR + Math.floor(length / 2), startC)
    }
    else
    {
        return dfs(n-1, startNum + (cnt * area), startR + Math.floor(length / 2), startC + Math.floor(length / 2))
    }
}

function FindArea(length, _r, _c) {
    if(goalR - _r <= Math.floor(length / 2) - 1 
    && goalC - _c <= Math.floor(length / 2) - 1) {
        return 0
    }

    if(goalR - _r <= Math.floor(length / 2) - 1 
    && goalC - _c <= length - 1) {
        return 1
    }

    if(goalR - _r <= length - 1 
    && goalC - _c <= Math.floor(length / 2) - 1) {
        return 2
    }

    else {
        return 3 
    }
}