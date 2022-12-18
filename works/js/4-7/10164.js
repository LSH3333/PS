let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [N,M,K] = input[0].split(' ').map(Number) 
let d = new Array(20).fill(0).map(() => new Array(20).fill(0))
let a = 0, b = 0

if(K != 0) {
    let R, C, cnt = 1
    for(r = 0; r < N; r++) {
        for(c = 0; c < M; c++) {
            if(cnt++ == K) {
                R = r 
                C = c 
                break 
            }
        }
    }

    // ~ R, C 
    for(r = 0; r <= R; r++) d[r][0] = 1
    for(c = 0; c <= C; c++) d[0][c] = 1
    for(r = 1; r <= R; r++) {
        for(c = 1; c <= C; c++) {
            d[r][c] = d[r-1][c] + d[r][c-1]
        }
    }
    a = d[R][C] 

    // R,C  ~ 
    for(r = R; r < N; r++) d[r][C] = 1;
    for(c = C; c < M; c++) d[R][c] = 1;        
    for(r = R+1; r < N; r++) {
        for(c = C+1; c < M; c++) {
                d[r][c] = d[r-1][c] + d[r][c-1];
        }
    }
    b = d[N-1][M-1];

    console.log(a*b) 
}
else {
    for(r = 0; r < N; r++) d[r][0] = 1;
    for(c = 0; c < M; c++) d[0][c] = 1;
    for(r = 1; r < N; r++) {
        for(c = 1; c < M; c++) {
            d[r][c] = d[r-1][c] + d[r][c-1]
        }
    }
    console.log(d[N-1][M-1])
}
