let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var [x1,y1,x2,y2] = input[0].split(' ').map(Number)
var [x3,y3,x4,y4] = input[1].split(' ').map(Number)

let abc = CCW(x1, y1, x2, y2, x3, y3) 
let abd = CCW(x1, y1, x2, y2, x4, y4)

let dca = CCW(x4, y4, x3, y3, x1, y1);
let dcb = CCW(x4, y4, x3, y3, x2, y2);

if(abc * abd < 0 && dca * dcb < 0) console.log(1) 
else console.log(0) 
    

function CCW(x1, y1, x2, y2, x3, y3) {
    let a = x1*y2 + x2*y3 + x3*y1;
    let b = x2*y1 + x3*y2 + x1*y3;

    if(a-b > 0) return 1 
    else return -1 
}

