let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let N = parseInt(input[0])
let like = new Array(410).fill(0).map(() => new Array(410).fill(false))
let board = new Array(21).fill(0).map(() => new Array(21).fill(0))
let dr = [-1, 0, 1, 0]
let dc = [0, 1, 0, -1]

let order = new Array(N*N).fill(0) 
for(i = 1; i <= N * N; i++) {
    let ip = input[i].split(' ').map(Number)
    let student = ip[0] 
    order[i] = student

    for(j = 1; j <= 4; j++) {
        let who = ip[j] 
        like[student][who] = true 
    }
}

// 자리 구함 
order.forEach(student => CalPos(student))
// 만족도 구함 
console.log(Cal())



function CalPos(student) {
    // {인접한 좋아하는 사람의 수, 인접한 비어있는 자리의 수}
    // 3d array 
    let v = new Array(N).fill(0).map(() => new Array(N).fill(0).map(() => new Array(2).fill(0)))
    let maxLike = 0 

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(board[i][j] != 0) continue 
            let likeCnt = 0, empty = 0 
            for(dir = 0; dir < 4; dir++) {
                let nr = i + dr[dir] 
                let nc = j + dc[dir] 
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue 
                if(board[nr][nc] == 0) empty++ 
                else likeCnt += like[student][board[nr][nc]]
            }
            maxLike = Math.max(maxLike, likeCnt)
            v[i][j][0] = likeCnt
            v[i][j][1] = empty 
        }
    }

    let maxEmpty = -1 
    let rPos = 0, cPos = 0 
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(board[i][j] != 0) continue 
            if(v[i][j][0] != maxLike) continue 
            if(v[i][j][1] > maxEmpty) {
                maxEmpty = v[i][j][1] 
                rPos = i 
                cPos = j
            }
        }
    }

    board[rPos][cPos] = student
}

function Cal() {
    let sum = 0 
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            let student = board[i][j] 
            let likeCnt = 0 
            
            for(dir = 0; dir < 4; dir++) {
                let nr = i + dr[dir] 
                let nc = j + dc[dir] 
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue 
                likeCnt += like[student][board[nr][nc]]
            }

            if(likeCnt == 0) sum += 0 
            else if(likeCnt == 1) sum += 1
            else if(likeCnt == 2) sum += 10 
            else if(likeCnt == 3) sum += 100 
            else sum += 1000 
        }
    }
    return sum 
}