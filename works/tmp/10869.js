let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let a = Number(input[0]);
let b = Number(input[1]);

console.log("%d", a+b);
console.log("%d", a-b);
console.log("%d", a*b);
console.log("%d", Math.floor(a/b));
console.log("%d", a%b);