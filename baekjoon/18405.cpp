#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, S, X, Y;
int board[202][202];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// [r][c]에 있는 바이러스 퍼뜨림
void Spread(int r, int c, vector<deque<pair<int,int>>> &virus)
{
    int virusNum = board[r][c];
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if(board[nr][nc] != 0) continue;
        board[nr][nc] = virusNum;
        virus[virusNum].push_back({nr, nc}); // 새로운 바이러스 좌표 푸쉬
    }
}

void SpreadVirus(vector<deque<pair<int,int>>> &virus)
{
    for(int i = 1; i <= K; i++)
    {
        int size = (int)virus[i].size();
        for(int j = 0; j < size; j++)
        {
            int r = virus[i].front().first;
            int c = virus[i].front().second;
            Spread(r, c, virus);
            virus[i].pop_front();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;
    vector<deque<pair<int,int>>> virus(K+1);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] != 0) virus[board[i][j]].push_back({i,j});
        }
    }
    cin >> S >> X >> Y;

    while(S--) SpreadVirus(virus);

    cout << board[X][Y];

}