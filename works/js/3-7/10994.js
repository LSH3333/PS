let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let N = parseInt(input[0])
var board = Array(2*2*(N-1)+1)
for(i = 0; i < board.length; i++) {
    board[i] = new Array(2*2*(N-1)+1)
}

Draw(N, 0, 0)

let ans = ""
for(i = 0; i < board.length; i++) {
    for(j = 0; j < board.length; j++) {
        if(board[i][j] == '*') ans += board[i][j]
        else ans += ' '
    }
    ans += '\n' 
}

console.log(ans)

function Draw(n, _r, _c) {
    if(n == 0) return 

    let len = 2 * 2 * (n-1) + 1 
    for(i = 0; i < len; i++) {
        board[_r+i][_c] = '*' 
        board[_r][_c+i] = '*' 
        board[_r+len-1][_c+i] = '*'
        board[_r+i][_c+len-1] = '*'
    }

    Draw(n-1, _r + 2, _c + 2)
}





