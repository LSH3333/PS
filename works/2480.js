let fs = require('fs');
<<<<<<< HEAD
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');
=======
let input = fs.readFileSync('/dev/stdin').toString().split(' ');
// let input = fs.readFileSync('input.txt').toString().split(' ');
>>>>>>> c56512b488a752420985d75bdb288e20446fb07f

a = parseInt(input[0])
b = parseInt(input[1])
c = parseInt(input[2])

<<<<<<< HEAD
if(a+b+c != 180) console.log("Error")
else if(a != b && b != c && c != a) console.log("Scalene")
else if((a==b && b!=c) || (b==c && a!=b) || (a==c && c!=b)) console.log("Isosceles")
else if(a == 60 && b == 60 && c == 60) console.log("Equilateral")
=======
res = 0 
if(a == b && b == c) 
    res = 10000 + a * 1000 
else if(a == b && b != c) 
    res = 1000 + a * 100 
else if(b == c && c != a) 
    res = 1000 + b * 100 
else if(a == c && b != a) 
    res = 1000 + a * 100 
else 
    res = Math.max(a,b,c) * 100 

console.log(res) 
    

>>>>>>> c56512b488a752420985d75bdb288e20446fb07f
