let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

v1 = input[0].split(' ').map(x => +x)
h = v1[0] 
m = v1[1]
s = v1[2] 
d = parseInt(input[1]) 

after = (h * 60 * 60) + (m * 60) + s + d 
hour = (Math.floor(after / (60*60))) % 24  
min = Math.floor(after / 60) % 60 
sec = after % (60)

console.log(hour, min, sec)

  