#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[51][51];

int res = 0;

// 현재 보드에서 같은 색으로 이루어져 있는 가장 긴 연속부분의 길이를 반환한다
int Calculate() {
    int hor_longest = 0;
    int ver_longest = 0;

    for(int i = 0; i < n; i++) {
        char hor_col = board[i][0];
        char ver_col = board[0][i];

        int hor_len = 1;
        int ver_len = 1;

        for(int j = 1; j < n; j++) {
            if(board[i][j] == hor_col) {
                hor_len++;
            }
            else {
                hor_longest = max(hor_len, hor_longest);
                hor_col = board[i][j];
                hor_len = 1;
            }

            if(board[j][i] == ver_col) {
                ver_len++;
            }
            else {
                ver_longest = max(ver_len, ver_longest);
                ver_col = board[j][i];
                ver_len = 1;
            }

        }
        hor_longest = max(hor_len, hor_longest);
        ver_longest = max(ver_len, ver_longest);
    }
    int bigger = max(ver_longest, hor_longest);

    return bigger;

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