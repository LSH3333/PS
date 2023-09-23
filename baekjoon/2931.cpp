#include <iostream>
using namespace std;

int R, C;
char board[26][26];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char pipesList[] = {'|', '-', '+', '1', '2', '3', '4'};

struct Data {
    int r, c, from;
};

Data GetNext(int r, int c, char block, int from) {
    int nr=-1,nc=-1,nfrom=-1;

    if(block == '|') {
        if(from == 0) {
            nfrom = 0;
        }
        else if(from == 2) {
            nfrom = 2;
        }
    } else if (block == '-') {
        if(from == 1) {
            nfrom = 1;
        }
        else if(from == 3) {
            nfrom = 3;
        }
    } else if (block == '+') {
        nfrom = from;
    } else if (block == '1') {
        if(from == 3) {
            nfrom = 2;
        }
        else if(from == 0) {
            nfrom = 1;
        }
    } else if (block == '2') {
        if(from == 2) {
            nfrom = 1;
        }
        else if(from == 3){
            nfrom = 0;
        }
    } else if (block == '3') {
        if(from == 1) {
            nfrom = 0;
        }
        else if(from == 2){
            nfrom = 3;
        }
    } else if(block == '4') {
        if(from == 1) {
            nfrom = 2;
        }
        else if(from == 0){
            nfrom = 3;
        }
    }

    if(nfrom != -1) {
        nr = r + dr[nfrom];
        nc = c + dc[nfrom];
    }

    return Data{nr,nc,nfrom};
}

bool dfs(int r, int c, int from) {
    char block = board[r][c];
    if (block == 'Z') {
        return true;
    }
    Data next = GetNext(r, c, block, from);
    int nr = next.r, nc = next.c, nfrom = next.from;

    // ???? ??? ??
    if(nfrom == -1 || nr < 1 || nr > R || nc < 1 || nc > C) {
        return false;
    }
    return dfs(nr, nc, nfrom);
}

int main() {
    int mR, mC;
    int startR, startC, startDir;

    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'M') {
                mR = i; mC = j;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        int nr = mR + dr[i], nc = mC + dc[i];
        if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if(board[nr][nc] != '.') {
            startR = nr;
            startC = nc;
            startDir = i;
        }
    }

    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            if(board[r][c] != '.') continue;
            for(int i = 0; i < 7; i++) {
                char pipe = pipesList[i];
                board[r][c] = pipe;
                bool res = dfs(startR, startC, startDir);
                board[r][c] = '.';

                if(res) {
                    cout << r << ' ' << c << ' ' << pipe;
                    return 0;
                }
            }
        }
    }

}