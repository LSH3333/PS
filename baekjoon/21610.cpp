#include <iostream>
#include <vector>
using namespace std;

int N, M;
// 물의 양, 구름 여부
pair<int, bool> board[52][52];

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};
// 대각 방향
int diagR[] = {-1, -1, 1, 1};
int diagC[] = {-1, 1, 1, -1};

// 1. 모든 구름이 d 방향으로 s칸 이동
void Move(int d, int s)
{
    // 새롭게 생기는 구름 좌표
    vector<pair<int,int>> newCloud;

    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(!board[r][c].second) continue;
            // s만큼 이동
            int nr = r, nc = c;
            for(int cnt = 0; cnt < s; cnt++)
            {
                nr = nr + dr[d];
                nc = nc + dc[d];
                if(nr == 0) nr = N;
                if(nr == N+1) nr = 1;
                if(nc == 0) nc = N;
                if(nc == N+1) nc = 1;
            }

            board[r][c].second = false;
            newCloud.push_back({nr,nc});
        }
    }

    for(auto x : newCloud)
    {
        board[x.first][x.second].second = true;
        board[x.first][x.second].first++; // 물 1 증가
    }

    // 4. 물이 증가한 칸에 물복사 버그
    for(auto x : newCloud)
    {
        int r = x.first, c = x.second;

        for(int dir = 0; dir < 4; dir++)
        {
            int nr = r + diagR[dir];
            int nc = c + diagC[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(board[nr][nc].first > 0) board[r][c].first++;
        }
    }

    // 5.
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(board[i][j].second) continue;
            if(board[i][j].first < 2) continue;
            board[i][j].first -= 2;
            board[i][j].second = true; // 구름 생성
        }
    }

    for(auto x : newCloud)
    {
        board[x.first][x.second].second = false; // 기존 구름 제거
    }
}

void Print()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << board[i][j].first <<','<<board[i][j].second << ' ';
        }cout<<endl;
    }cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> board[i][j].first;
            board[i][j].second = false;
        }
    }

    // 비바라기 시전
    board[N][1].second = true;
    board[N][2].second = true;
    board[N-1][1].second = true;
    board[N-1][2].second = true;

    for(int i = 0; i < M; i++)
    {
        int d, s; cin >> d >> s;
        Move(d-1, s);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            answer += board[i][j].first;
        }
    }

    cout << answer;
}