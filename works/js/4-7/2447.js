let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let N = parseInt(input[0]) 
let prev = new Array(1).fill(0).map(() => new Array(1).fill('*'))
recur(3, prev)


function recur(n, prev) {
    if(n > N) {
        Print(prev)
        return;
    }

    // callback is invoked only for indexes of the array which have assigned value 
    let board = new Array(n).fill(0).map(() => new Array(n).fill(' '))
    
    let r = 0, c = 0 
    for(cnt = 0; cnt < 9; cnt++) {
        if(cnt != 4) {
            for(i = r; i < r + Math.floor(n/3); i++) {
                for(j = c; j < c + Math.floor(n/3); j++) {
                    board[i][j] = prev[i-r][j-c]
                }
            }
        }

        if(c + Math.floor(n/3) >= n) {
            r = r + Math.floor(n / 3)
            c = 0 
        }
        else {
            c = c + Math.floor(n / 3)
        }

    }

    recur(n*3, board) 
}

function Print(prev) {
    let answer = "" 
    for(i = 0; i < prev.length; i++) {
        for(j = 0; j < prev[i].length; j++) {
            answer += prev[i][j] 
        }
        answer += '\n' 
    }
    console.log(answer) 
}