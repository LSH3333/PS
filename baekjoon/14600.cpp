#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int K;
int x, y, len;
int board[5][5];

void Print() {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void dfs(int idx, int num, int cnt) {
    if (idx == len * len) {
        if((K == 1 && cnt == 1) || (K == 2 && cnt == 5)) {
            Print();
        }
        return;
    }

    int r = idx / len;
    int c = idx % len;

    //
    if (r + 1 < len && c + 1 < len && board[r][c] == 0 && board[r + 1][c] == 0 && board[r][c + 1] == 0) {
        board[r][c] = num;
        board[r+1][c] = num;
        board[r][c+1] = num;
        dfs(idx+1, num+1, cnt+1);
        board[r][c] = 0;
        board[r+1][c] = 0;
        board[r][c+1] = 0;
    }

    //
    if (c + 1 < len && r + 1 < len && board[r][c] == 0 && board[r][c + 1] == 0 && board[r + 1][c + 1] == 0) {
        board[r][c] = num;
        board[r][c+1] = num;
        board[r+1][c+1] = num;
        dfs(idx+1, num+1, cnt+1);
        board[r][c] = 0;
        board[r][c+1] = 0;
        board[r+1][c+1] = 0;
    }

    //
    if (c + 1 < len && r + 1 < len && board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0) {
        board[r][c+1] = num;
        board[r+1][c+1] = num;
        board[r+1][c] = num;
        dfs(idx + 1, num + 1, cnt+1);
        board[r][c+1] = 0;
        board[r+1][c+1] = 0;
        board[r+1][c] = 0;
    }

    //
    if (r + 1 < len && c + 1 < len && board[r][c] == 0 && board[r + 1][c] == 0 && board[r + 1][c + 1] == 0) {
        board[r][c] = num;
        board[r+1][c] = num;
        board[r+1][c+1] = num;
        dfs(idx + 1, num + 1, cnt+1);
        board[r][c] = 0;
        board[r+1][c] = 0;
        board[r+1][c+1] = 0;
    }

    //
    dfs(idx + 1, num + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K >> x >> y;
    len = (int)pow(2, K);
    board[len-y][x-1] = -1;



    dfs(0, 1, 0);
}