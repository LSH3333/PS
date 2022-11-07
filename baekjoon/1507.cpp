#include <iostream>
using namespace std;

int N;
int board[21][21];
int d[21][21];
int answer;


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            d[i][j] = board[i][j];
        }
    }


    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == k || j == k) continue;

                // 바로 가는 길이 더 크면 해당 길 없음
                if(board[i][k] + board[k][j] < board[i][j]) {
                    cout << -1;
                    return 0;
                }

                // 거쳐가는 길과 바로 가는 길이 같다면
                if(board[i][k] + board[k][j] == board[i][j]) {
                    d[i][j] = 0; // 바로가는길 제거
                }

            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            answer += d[i][j];
        }
    }


    cout << answer;

}

