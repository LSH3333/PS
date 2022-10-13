let fs = require('fs');
// let input = fs.readFileSync('input.txt').toString().split('\n');
let input = fs.readFileSync(0).toString().trim().split('\n');

var N = parseInt(input[0])
var ans = 0 

for(i = 1; i <= N; i++) {
    var [student, apple] = input[i].split(' ').map(Number) 
    var left = Math.floor(apple % student)
    ans += left 
}
console.log(ans) 