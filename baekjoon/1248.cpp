#include <iostream>
using namespace std;

char board[15][15];
int N;
int answer[15];

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

bool IsOk(int c) {
    int sum = 0;

    for(int r = c; r >= 0; r--) {
        sum = sum + answer[r];
        if(sum > 0 && board[r][c] != '+') return false;
        if(sum < 0 && board[r][c] != '-') return false;
        if(sum == 0 && board[r][c] != '0') return false;
    }
    return true;
}

void dfs(int idx) {
    if(idx == N) {
        for(int i = 0; i < N; i++) {
            cout << answer[i] << ' ';
        }
        exit(0);
    }

    for(int i = -10; i <= 10; i++) {
        answer[idx] = i;
        if(IsOk(idx)) {
            dfs(idx+1);
        }
    }

}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0);

}