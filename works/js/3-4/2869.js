let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

// 하루에 A-B 이동 가능 
// V-A 미터 가는데 걸리는 일수 

var [A, B, V] = input[0].split(' ').map(Number) 
var oneDay = A - B  // 4 
var goal = V - A   // 1

if(A + oneDay * Math.floor(goal / oneDay) >= V) {
    console.log(Math.floor(goal / oneDay) + 1)
}
else {
    console.log(Math.floor(goal / oneDay) + 2)
}