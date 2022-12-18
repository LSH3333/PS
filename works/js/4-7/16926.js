let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [N,M,R] = input[0].split(' ').map(Number) 
let before = new Array(N)
let after = new Array(N).fill(0).map(() => new Array(M).fill(0))

for(idx = 0; idx < N; idx++) {   
    before[idx] = input[idx+1].split(' ').map(Number) 
}

let r = 0, c = 0, H = N, W = M 
while(true) {
    CalOneRec(r, c, H, W) 
    r++
    c++
    H -= 2 
    W -= 2
    if(H < 2 || W < 2) break 
}

Print() 


function CalOneRec(_r, _c, H, W) {
    let length = (H + W) * 2 - 4 
    let v = new Array(length)
    let r = _r, c = _c, idx = 0 

    // down 
    for(; r < _r + H; r++, idx++) {
        CalPosition(r, c, idx, v) 
    }
    r--

    // right 
    for(c = c +1; c < _c + W; c++, idx++) {
        CalPosition(r, c, idx, v) 
    }
    c-- 

    // up 
    for(r = r-1; r >= _r; r--, idx++) {
        CalPosition(r, c, idx, v) 
    }
    r++ 

    // left 
    for(c = c-1; c >= _c; c--, idx++) {
        CalPosition(r, c, idx, v) 
    }

    // 
    r = _r, c = _c;
    idx = 0;
    // down
    for(; r < _r+H; r++, idx++)
    {
        after[r][c] = v[idx];
    }
    r--;

    // right
    for(c = c+1; c < _c+W; c++, idx++)
    {
        after[r][c] = v[idx];
    }
    c--;

    // up
    for(r = r-1; r >= _r; r--, idx++)
    {
        after[r][c] = v[idx];
    }
    r++;

    // left
    for(c = c-1; c >= _c+1; c--, idx++)
    {
        after[r][c] = v[idx];
    }
}

function CalPosition(r, c, idx, v) {
    let num = before[r][c] 
    v[(idx + R) % v.length] = num
}

function Print() {
    let answer = "" 
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            answer += `${after[i][j]} ` 
        }
        answer += '\n' 
    }
    console.log(answer) 
}