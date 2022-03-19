#include <iostream>
using namespace std;

int M, N;
int a[510][510];
int d[510][510];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(int r, int c)
{
    // 도착지점
    if(r == M-1 && c == N-1)
    {
        return 1;
    }
    // 아직 방문안한 지점임
    if(d[r][c] == -1)
    {
        // 도착지점인지는 아직 모르나, 방문 기록해놓음
        d[r][c] = 0;
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if(a[nr][nc] >= a[r][c]) continue;

            d[r][c] += dfs(nr, nc);
        }
    }

    // 이미 방문한 지점임: 도착루트가 아니라면 0이 리턴될것
    return d[r][c];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    // 세로 M, 가로 N
    cin >> M >> N;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
            d[i][j] = -1; // d 배열 -1로 초기화
        }
    }

    dfs(0, 0);

//    for(int i = 0; i < M; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            cout << d[i][j] << ' ';
//        } cout << endl;
//    } cout << endl;

    cout << d[0][0];
}