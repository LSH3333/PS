#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
char board[1001][1001];
pair<int,int> emp[1001][1001];
int answer[1001][1001];
bool checked[1000010];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int empIdx = 1;

void bfs(int _r, int _c, vector<vector<bool>> &empVisited)
{
    vector<pair<int,int>> visited;
    queue<pair<int,int>> q;
    int count = 0;
    empVisited[_r][_c] = true;
    emp[_r][_c].second = empIdx;
    q.push({_r,_c});
    visited.push_back({_r, _c});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        count++;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == '1' || empVisited[nr][nc]) continue;
            visited.push_back({nr, nc});
            empVisited[nr][nc] = true;
            q.push({nr,nc});
            emp[nr][nc].second = empIdx;
        }
    }

    for(auto x : visited)
    {
        emp[x.first][x.second].first = count % 10;
    }
    empIdx++;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 비어 있는 공간들 계산
    vector<vector<bool>> empVisited(N+1, vector<bool>(M+1, false));
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            if(board[r][c] == '1' || empVisited[r][c]) continue;
            bfs(r, c, empVisited);
        }
    }


    // 각 벽 허물고 계산
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            if(board[r][c] == '0')
            {
                answer[r][c] = 0;
            }
            else
            {
                vector<int> checkedNum;
                answer[r][c] = 1;
                for(int dir = 0; dir < 4; dir++)
                {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    int nextIdx = emp[nr][nc].second;
                    if(board[nr][nc] == '1' || checked[nextIdx]) continue;
                    checked[nextIdx] = true;
                    checkedNum.push_back(nextIdx);
                    answer[r][c] += (emp[nr][nc].first % 10);
                }

                for(auto x : checkedNum) checked[x] = false;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << (answer[i][j] % 10);
        } cout << '\n';
    }
}