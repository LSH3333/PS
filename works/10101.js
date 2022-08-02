let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

a = parseInt(input[0])
b = parseInt(input[1])
c = parseInt(input[2])

if(a+b+c != 180) console.log("Error")
else if(a != b && b != c && c != a) console.log("Scalene")
else if((a==b && b!=c) || (b==c && a!=b) || (a==c && c!=b)) console.log("Isosceles")
else if(a == 60 && b == 60 && c == 60) console.log("Equilateral")