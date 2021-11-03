#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[51][51];

int res = 0;

// 현재 보드에서 같은 색으로 이루어져 있는 가장 긴 연속부분의 길이를 반환한다
int Calculate() {
    // hor
    int hor_len = 1;
    for(int i = 0; i < n; i++) {
        char col = board[i][0];
        int len = 1;

        for(int j = 1; j < n; j++) {
            if(board[i][j] == col) {
                len++;
            }
            else {
                hor_len = max(hor_len, len);
                col = board[i][j];
                len = 1;
            }
        }
        hor_len = max(hor_len, len);
    }

    // ver
    int ver_len = 1;
    for(int i = 0; i < n; i++) {
        char col = board[0][i];
        int len = 1;

        for(int j = 1; j < n; j++) {
            if(board[j][i] == col) {
                len++;
            }
            else {
                ver_len = max(ver_len, len);
                col = board[j][i];
                len = 1;
            }
        }
        ver_len = max(ver_len, len);
    }

    return max(hor_len, ver_len);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            // 좌우
            swap(board[i][j], board[i][j+1]);
            res = max(res, Calculate());
            swap(board[i][j], board[i][j+1]); // 원상태로

            // 상하
            swap(board[j][i], board[j+1][i]);
            res = max(res, Calculate());
            swap(board[j][i], board[j+1][i]);
        }
    }

    cout << res;
}