let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');
v = input[0].split(' ').map(x => parseInt(x)) 

numOfSongs = v[0] 
avg = v[1]-1  
ans = avg * numOfSongs
console.log(ans+1)