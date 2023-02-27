let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

const U = 0, R = 1, D = 2, L = 3


let [r1, c1, r2, c2] = input[0].split(' ').map(Number) 
let arr = new Array(50).fill(0).map(() => new Array(50).fill(0))
let goalCnt = (r2-r1+1) * (c2-c1+1) 
let cnt = 0, r = 0, c = 0, num = 1, len = 5, dir = U 

while(goalCnt > 0) {

    // arr 범위 내
    if(r >= r1 && r <= r2 && c >= c1 && c <= c2) {
        arr[r + r1 * -1][c + c1 * -1] = num;
        goalCnt--;
    }
    if(goalCnt == 0) break;

    FindNextPos() 
}

Print() 




function FindNextPos() {
    if(num <= 9) {
        if(num == 1 || num == 7 || num == 8 || num == 9) {
            RIGHT();
        }
        else if(num == 2) {
            UP();
        }
        else if(num == 3 || num == 4) {
            LEFT();
        }
        else if(num == 5 || num == 6) {
            DOWN();
        }
    }
    else {
        cnt++ 
        
        if(dir == U) {
            UP();
            if(cnt == len-2) {dir = L; cnt = 0;}
        }
        else if(dir == D) {
            DOWN();
            if(cnt == len-1) {dir = R; cnt = 0;}
        }
        else if(dir == L) {
            LEFT();
            if(cnt == len-1) {dir = D; cnt = 0;}
        }
        else if(dir == R) {
            RIGHT();
            if(cnt == len) { cnt = 0; len += 2; dir = U; }
        }   
    }

    num++
}

function UP() {r--}
function RIGHT() {c++}
function DOWN() {r++}
function LEFT() {c--}

function Print() {
    let strLen = num.toString().length
    let answer = ""
    
    for(r = 0; r < r2-r1+1; r++) {
        for(c = 0; c < c2-c1+1; c++) {
            let s = arr[r][c].toString()
            s = s.padStart(strLen, ' ') 
            s += ' ' 
            answer += s 
        }
        answer += '\n'
    }

    console.log(answer)
}