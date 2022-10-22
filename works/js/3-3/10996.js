let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
var arr = new Array(2)
for(i = 0; i < arr.length; i++) {
    arr[i] = new Array(N)
    arr[i].fill(' ') 
} 

var r = 0, c = 0 
for(i = 1; i <= N; i++) {
    arr[r][c] = '*'
    r = (r + 1) % 2
    c = c + 1 
}

var ans = "" 
for(i = 0; i < N; i++) {
    
    for(j = 0; j < arr.length; j++) {
        for(k = 0; k < arr[j].length; k++) {
            ans += arr[j][k]
        }
        ans += '\n'
    }
}
console.log(ans) 
