let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let arr = [] 
let [H,W] = input[0].split(' ').map(Number) 
let N = parseInt(input[1])
for(let i = 2; i < input.length; i++) {
    let [h,w] = input[i].split(' ').map(Number)
    arr.push([h, w])
}


let answer = 0 
for(let i = 0; i < N; i++) {
    for(let j = i+1; j < N; j++) {

        let h1 = arr[i][0], w1 = arr[i][1], h2 = arr[j][0], w2 = arr[j][1]
        
        if(TryPutStickers(h1, w1, h2, w2)) {
            answer = Math.max(answer, h1*w1+h2*w2)
        }
        
    }
}

console.log(answer) 



function DoesItFit(r, c, h, w, mark) {
    if(r + h - 1 >= H || c + w - 1 >= W) return false;
    for(i = r; i < r + h; i++) {
        for(j = c; j < c + w; j++) {
            if(mark[i][j]) return false;
        }
    }
    return true;
}

function PutSticker(r, c, h, w, mark) {
    for(i = r; i < r + h; i++) {
        for(j = c; j < c + w; j++) {
            mark[i][j] = true;
        }
    }
}

function TryPutSticker(h, w, mark) {
    for(r = 0; r < H; r++) {
        for(c = 0; c < W; c++) {
            if(DoesItFit(r, c, h, w, mark)) {
                PutSticker(r, c, h, w, mark);
                return true;
            }
        }
    }
    return false;
}

function TryPutStickers(h1, w1, h2, w2) {
    let mark = new Array(H).fill(0).map(() => new Array(W).fill(false))


    if(TryPutSticker(h1, w1, mark) && TryPutSticker(h2, w2, mark)) return true
    mark = new Array(H).fill(0).map(() => new Array(W).fill(false))

    if(TryPutSticker(w1, h1, mark) && TryPutSticker(h2, w2, mark)) return true;
    mark = new Array(H).fill(0).map(() => new Array(W).fill(false))

    if(TryPutSticker(h1, w1, mark) && TryPutSticker(w2, h2, mark)) return true;
    mark = new Array(H).fill(0).map(() => new Array(W).fill(false))

    if(TryPutSticker(w1, h1, mark) && TryPutSticker(w2, h2, mark)) return true;
    
    return false;
}