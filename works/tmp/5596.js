let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

v1 = input[0].split(' ').map(x => +x)
v2 = input[1].split(' ').map(x => +x) 

sum1 = 0
for(x in v1) sum1 += v1[x]
sum2 = 0
for(x in v2) sum2 += v2[x]

if(sum1 >= sum2) console.log(sum1)
else console.log(sum2)


