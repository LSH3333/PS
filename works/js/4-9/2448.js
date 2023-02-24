let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0])
let H = N, W = 2 * H - 1
let arr = new Array(H).fill(0).map(() => new Array(W).fill(' '))

MakeTriangle(3, 0, Math.floor(W / 2) - 1) 
Print()

function Print() {
    for(i = 0; i < H; i++) {
        let ans = ""
        for(j = 0; j < W; j++) {
            ans += arr[i][j] 
        } 
        console.log(ans)
    }
}

function MakeTriangle(n, _r, _c) {
    if(n > N) return 

    if(n == 3) {
        w = Math.floor(W/2)
        arr[0][w] = '*' 
        arr[1][w-1] = '*'; arr[1][w+1] = '*';
        for(i = w-2; i <= w+2; i++) arr[2][i] = '*'
        MakeTriangle(n*2, 0, w-2) 
    }
    else {
        let div = Math.floor(n/2)
        for(r = _r; r < _r + div; r++) {
            for(c = _c; c < _c + (div*2-1); c++) {
                arr[r+div][c-div] = arr[r][c];
                arr[r+div][c+div] = arr[r][c];
            }
        }
        MakeTriangle(n*2, 0, _c - div) 
    }
}

