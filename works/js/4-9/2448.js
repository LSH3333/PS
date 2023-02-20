let fs = require('fs');
// let input = fs.readFileSync(0).toString().trim().split('\n')
let input = fs.readFileSync('input.txt').toString().split('\n')

let H = parseInt(input[0])
let W = 2 * H - 1
let arr = new Array(6200).fill(0).map(() => new Array(6200).fill(' '))


arr[0][2] = '*'
arr[1][1] = '*'
arr[1][3] = '*'
for(i = 0; i < 5; i++) {
    arr[2][i] = '*'
}

let l = 3 
while(l < H) {
    Copy(l) 
    l *= 2
}

let answer = ""
for(i = 0; i < H; i++) {
    for(j = 0; j < W; j++) {
        answer += arr[i][j] 
    }
    answer += '\n'
}
console.log(answer)



function Copy(h) {
    let w = 2 * h - 1

    for(i = 0; i < h; i++) {
        memcpy(h+i, 0, i, w) 
        memcpy(h+i, w+1, i, w)
        memset(i, ' ', w)
    }
    for(i = 0; i < h; i++) {
        memcpy(i, Math.floor(w/2)+1, h+i, w)
    }
}

function memcpy(dest_r, dest_c, src, w) {
    for(i = 0; i < w; i++) {
        arr[dest_r][dest_c+i] = arr[src][i]
    }
}

function memset(idx, c, len) {
    for(i = 0; i < len; i++) {
        arr[idx] = c 
    }
}