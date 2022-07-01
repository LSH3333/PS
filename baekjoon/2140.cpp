#include <iostream>
#include <vector>
using namespace std;

int N;
// 판별안됨:-1, 지뢰확정:0, 지뢰아님확정:1
int board[101][101];

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Check(int r, int c)
{
    int mine = 0; // 지뢰
    int notSure = 0;
    vector<pair<int,int>> notSurePos;
    for(int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 1 || nr >= N-1 || nc < 1 || nc >= N-1) continue; // 태두리도 제외
        if(board[r][c] == 0) { board[nr][nc] = 1; continue; }// 주위 지뢰 예상수 0이라면 주위 모두 지뢰 아님 확정 처리
        if(board[nr][nc] == 0) mine++;
        else if(board[nr][nc] == -1) { notSure++; notSurePos.push_back({nr,nc}); }
    }
    if(board[r][c] == 0) return; // 주위 지뢰 예상수 0이면 이후 처리 불필요

    // 주위 지뢰 확정 수와 주위 예상 지롸수가 같다면, 나머지 불확실한 곳은 모두 지뢰 아님 확정
    if(mine == board[r][c])
    {
        for(auto x : notSurePos)
        {
            board[x.first][x.second] = 1;
        }
    }
    // 주위 불확실한 곳 수와 주위 예상 지뢰수가 같다면, 모든 불확실한 곳 지뢰 확정
    else if(notSure == board[r][c])
    {
        for(auto x : notSurePos)
        {
            board[x.first][x.second] = 0;
        }
    }
    // 주위 불확실한 곳 수 + 주위 확정 지뢰수 == 주위 예상 지뢰수라면, 모든 불확실한곳 지뢰 확정
    else if(notSure + mine == board[r][c])
    {
        for(auto x : notSurePos)
        {
            board[x.first][x.second] = 0;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int total = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < N; j++)
        {
            char c = str[j];
            if(c == '#')
            {
                total++;
                board[i][j] = -1;
            }
            else
            {
                board[i][j] = c-'0';
            }
        }
    }

    // 태두리 돌면서 지뢰 체크
    for(int r = 0; r < N; r++)
    {
        if(r == 0 || r == N-1)
        {
            for(int c = 0; c < N; c++) Check(r, c);
        }
        else
        {
            Check(r, 0); Check(r, N-1);
        }
    }
    // 태두리 제외한 가운데 부분 에서 지뢰 아님 확정 몇개인지 카운트
    int notMine = 0;
    for(int r = 1; r < N-1; r++)
    {
        for(int c = 1; c < N-1; c++)
        {
            if(board[r][c] == 1) notMine++;
        }
    }

    cout << total - notMine;

}