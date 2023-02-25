let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

/**
 * n=1: (1,1)
 * n=2: (3,5)
 * n=3: (7,13)
 * n=4: (15, 29)
 *
 *  r[n-1] * 2 + 1, r[n] * 2 - 1
 */

let N = parseInt(input[0])
let arr = new Array(1200).fill(0).map(() => new Array(2400).fill(' '))
let length = new Array(11).fill(0).map(() => new Array(2).fill(0))

MakeLength() 
// 역삼각형 
if(N % 2 == 0) {
    MakeTriangles(N, length[N][0]-1, Math.floor(length[N][1] / 2));    
}
else {
    MakeTriangles(N, 0, Math.floor(length[N][1] / 2));
}

Print() 




function MakeLength() {
    for(i = 1; i <= 10; i++) {
        length[i][0] = length[i-1][0] * 2 + 1;
        length[i][1] = length[i][0] * 2 - 1;
    }
}

function MakeTriangles(n, _r, _c) {
    if(n == 0) return 

    let rLen = length[n][0] 

    // 역삼각형
    if(n % 2 == 0) {
        DrawTriangle(n, _r, _c, false);
        MakeTriangles(n-1, _r - rLen + 2, _c);
    }
    // 삼각형
    else {
        DrawTriangle(n, _r, _c, true);
        MakeTriangles(n-1, _r + rLen - 2, _c);
    }
}

function DrawTriangle(n, _r, _c, tri) {
    let rLen = length[n][0], cLen = length[n][1] 

    // 삼각형 
    if(tri) {
        let r = _r, lc = _c, rc = _c 
        let cnt = 0 
        while(cnt++ < rLen) {
            arr[r][lc] = '*';
            arr[r][rc] = '*';
            r++;
            lc--; rc++;
        }

        r = _r + rLen - 1
        let c = _c - Math.floor(cLen / 2 ) 
        cnt = 0 
        while(cnt < cLen) {
            arr[r][c++] = '*';
            cnt++;
        }
    }
    // 역삼각형 
    else {
        let r = _r, lc = _c, rc = _c 
        let cnt = 0 
        while(cnt++ < rLen) {
            arr[r][lc] = '*';
            arr[r][rc] = '*';
            r--;
            lc--; rc++;
        }

        r = _r - rLen + 1
        let c = _c - Math.floor(cLen / 2) 
        cnt = 0
        while(cnt < cLen) {
            arr[r][c++] = '*';
            cnt++;
        }
    }
}

function Print() {
    let rLen = length[N][0], cLen = length[N][1] 

    if(N % 2 == 0) {
        for(i = 0; i < rLen; i++) {
            let ans = ""
            for(j = 0; j < cLen-i; j++) {
                ans += arr[i][j]
            }
            console.log(ans)
        }
    }
    else {
        for(i = 0; i < rLen; i++) {
            let ans = ""
            for(j = 0; j <= Math.floor(cLen / 2) + i; j++) {
                ans += arr[i][j] 
            }
            console.log(ans)
        }
    }
}