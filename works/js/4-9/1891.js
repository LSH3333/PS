let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [d, ip] = input[0].split(' ')
ip = ip.trimEnd()
let [toRight, toUp] = input[1].split(' ').map(Number) 
let len = Math.pow(2, ip.length)

let answer = ""
let beginR = 0, beginC = 0, endR = 0, endC = 0

FindPos(ip, 0, len, 0, 0)

// 도착한 사분면 위치
endR = beginR + toUp*-1;
endC = beginC + toRight;

// 존재하지 않는 사분면인 경우
if(endR < 0 || endR >= len || endC < 0 || endC >= len) {
    console.log(-1)
}
else {
    FindQuadrant(len, 0, 0) 
    console.log(answer)
}



// 사분면 정보로 좌표 찾음 
function FindPos(ip, idx, len, _r, _c) {
    if(idx >= ip.length) {
        beginR = _r 
        beginC = _c
        return 
    }

    let pos = parseInt(ip[idx])

    if(pos == 1) {
        FindPos(ip, idx+1, len/2, _r, _c + len / 2);
    }
    else if(pos == 2) {
        FindPos(ip, idx+1, len/2, _r, _c);
    }
    else if(pos == 3) {
        FindPos(ip, idx+1, len/2, _r + len / 2, _c);
    }
    else {
        FindPos(ip, idx + 1, len / 2, _r + len / 2, _c + len / 2);
    }
}

function FindQuadrant(len, _r, _c) {
    if(len == 1){
        return
    }

    let subR = endR - _r 
    let subC = endC - _c 

    let lenDiv2 = Math.floor(len/2)
    // 2
    if(subR < lenDiv2 && subC < lenDiv2) {        
        answer += "2"
        FindQuadrant(lenDiv2, _r, _c);
    }
    // 1
    else if(subR < lenDiv2 && subC >= lenDiv2) {
        answer += "1"
        FindQuadrant(lenDiv2, _r, _c + lenDiv2);
    }
    // 3
    else if(subR >= lenDiv2 && subC < lenDiv2) {
        answer += "3"
        FindQuadrant(lenDiv2, _r + lenDiv2, _c);
    }
    else {
        answer += "4"
        FindQuadrant(lenDiv2, _r + lenDiv2, _c + lenDiv2);
    }
}