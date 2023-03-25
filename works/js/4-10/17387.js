let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

var [x1, y1, x2, y2] = input[0].split(' ').map(Number)
var [x3, y3, x4, y4] = input[1].split(' ').map(Number) 

var abc = CCW(x1,y1,x2,y2,x3,y3)
var abd = CCW(x1,y1,x2,y2,x4,y4)

var cda = CCW(x3,y3,x4,y4,x1,y1)
var cdb = CCW(x3,y3,x4,y4,x2,y2)

var answer = 0 
if(abc * abd == 0 && cda * cdb == 0) {
    if(Cal(x1,y1,x2,y2,x3,y3,x4,y4)) {
        answer = 1
    }
    else {
        answer = 0
    }
}
else {
    if(abc * abd <= 0 && cda * cdb <= 0) {
        answer = 1
    }
    else {
        answer = 0
    }
}

console.log(answer)



function CCW(x1, y1, x2, y2, x3, y3) {
    var a = x1*y2 + x2*y3 + x3*y1;
    var b = x2*y1 + x3*y2 + x1*y3;

    if(a-b == 0) return 0;
    if(a-b > 0) return 1;
    else return -1;
}

function Cal(x1, y1, x2, y2, x3, y3, x4, y4) {
    if(x1 == x2 && x2 == x3 && x3 == x4) {
        var a=y1,b=y2,c=y3,d=y4;
        if(y1 > y2) { a = y2; b = y1; }
        if(y3 > y4) { c = y4; d = y3; }
        if(a <= d && c <= b) return true;
        else return false;
    }
    else {
        var a=x1,b=x2,c=x3,d=x4;
        if(x1 > x2) { a = x2; b = x1; }
        if(x3 > x4) { c = x4; d = x3; }
        if(a <= d && c <= b) return true;
        else return false;
    }
}