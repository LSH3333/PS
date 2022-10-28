let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var [X, Y] = input[0].split(' ')

function Rev(x) {
    var rev = x.split('').reverse().join('')
    return parseInt(rev) 
}

var ans = Rev(X) + Rev(Y) 
console.log(Rev(ans.toString()))

