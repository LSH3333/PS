let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let answer = "" 
let [x1,y1,x2,y2] = input[0].split(' ').map(Number)
let [x3,y3,x4,y4] = input[1].split(' ').map(Number) 

let x = getState(x1, x2, x3, x4) 
let y = getState(y1, y2, y3, y4) 

if(x == 0 || y == 0) {
    answer = "NULL"
}
else if(x == 1) {
    y == 1 ? answer = "POINT" : answer = "LINE"
}
else if(x == 2) {
    y == 1 ? answer = "LINE" : answer = "FACE"
}

console.log(answer) 

function getState(v1, v2, v3, v4) {
    if(v2 < v3 || v4 < v1) return 0 
    else if(v2 == v3 || v4 == v1) return 1 
    return 2
}

