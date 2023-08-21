#include <iostream>
using namespace std;

int N;
int board[130][130];

bool Check(int len, int r, int c) {
    for(int i = r; i < r+len; i++) {
        for(int j = c; j < c+len; j++) {
            if(board[i][j] != board[r][c]) return false;
        }
    }
    return true;
}

int blue, white;
void Cal(int r, int c, int len) {
    if (Check(len, r, c)) {
        if(board[r][c] == 1) blue++;
        else white++;
        return;
    }

    Cal(r, c, len / 2);
    Cal(r, c+len/2, len/2);
    Cal(r+len/2, c, len/2);
    Cal(r+len/2, c+len/2, len/2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    Cal(0, 0, N);
    cout << white << '\n' << blue;
}