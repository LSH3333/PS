#include <iostream>
using namespace std;

// boundary 늘려줌
int board[120][120];
long long d[120][120];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    // 도착지점
    d[N-1][N-1] = 1;

    for(int i = N-1; i >= 0; i--)
    {
        for(int j = N-1; j >= 0; j--)
        {
            if(i == N-1 && j == N-1) continue;
            int distance = board[i][j];
            // 오른쪽으로 distance칸 떨어진 곳의 경우의수 + 아래로 distance칸 떨어진 곳의 경우의 수
            d[i][j] = d[i][j+distance] + d[i+distance][j];
        }
    }

    cout << d[0][0];
}