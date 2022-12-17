let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let answer = "" 
let tc = parseInt(input[0]) 
for(t = 1; t <= tc; t++) {
    var [x, y] = input[t].split(' ').map(Number) 
    var distance = y - x 
    var ans = dfs(distance, 0, 0) 
    answer += ans + '\n' 
}

console.log(answer) 


function dfs(distance, moved, cnt) {
    if(distance == 0) return cnt 

    for(move = moved+1; move >= moved-1; move--) {
        if(move <= 0) continue 
        let sum = Math.floor((move * (move+1)) / 2)
        if(sum <= distance) {
            return dfs(distance-move, move, cnt+1) 
        } 
    }
}
