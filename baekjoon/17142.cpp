#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int original_board[51][51];
int total = 0; // 최종적으로 바이러스가 있어야 하는 칸의 갯수
int answer = 2000000000;

#define VIRUS 2
#define WALL 1
#define EMPTY 0

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


// 정한 M개의 위치를 활성 바이러스로 바꿈
// 모든 곳 바이러스 감염 완료면 시간 리턴, 아니면 -1 리턴
int StartVirus(const vector<pair<int,int>> &selectedVirus)
{
    // 보드 복사해옴
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<bool>> mark(N, vector<bool>(N, false));

    // 활성 바이러스 놓음
    queue<pair<int,int>> q;
    for(const auto &x : selectedVirus)
    {
        mark[x.first][x.second] = true;
        q.push({x.first, x.second});
    }
    int cnt = 0;
    int maxTime = 0;
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(mark[nr][nc] || original_board[nr][nc] == WALL) continue;
            mark[nr][nc] = true;
            q.push({nr, nc});
            board[nr][nc] = board[r][c] + 1;
            if(original_board[nr][nc] != VIRUS)
            {
                maxTime = max(maxTime, board[nr][nc]);
                cnt++;
            }
        }
    }

    if(cnt == total) return maxTime;
    else return -1;
}

// M 개의 바이러스 위치 결정함
void dfs(int idx, int depth, vector<pair<int,int>> &virusPos, vector<pair<int,int>> &selectedVirus, vector<bool> &mark)
{
    // M개 찾음
    if(depth == M)
    {
        int res = StartVirus(selectedVirus);
        if(res != -1) answer = min(answer, res);

        return;
    }

    for(int i = idx; i < virusPos.size(); i++)
    {
        pair<int,int> p = virusPos[i];
        if(mark[i]) continue;
        mark[i] = true;
        selectedVirus.push_back({p.first, p.second});
        dfs(i, depth+1, virusPos, selectedVirus, mark);
        mark[i] = false;
        selectedVirus.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int,int>> virusPos; // 바이러스 위치 기록

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int n; cin >> n;
            if(n == 0) { original_board[i][j] = EMPTY; total++; }// 빈 공간
            else if(n == 1) original_board[i][j] = WALL; // 벽
            else
            {
                original_board[i][j] = VIRUS; // 바이러스 최초 위치
                virusPos.push_back({i,j});
            }
        }
    }

    vector<pair<int,int>> selectedVirus;
    vector<bool> mark(M, false);
    dfs(0, 0, virusPos, selectedVirus, mark);

    if(answer == 2000000000) cout << -1;
    else cout << answer;
}