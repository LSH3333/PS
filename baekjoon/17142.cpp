#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int original_board[51][51];
int total = 0; // 최종적으로 바이러스가 있어야 하는 칸의 갯수

#define VIRUS (-3)
#define WALL (-2)
#define EMPTY (-1)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};



// 정한 M개의 위치를 활성 바이러스로 바꿈
int StartVirus(const vector<pair<int,int>> &selectedVirus)
{
    // 보드 복사해옴
    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = original_board[i][j];
        }
    }

    // 활성 바이러스 놓음
    queue<pair<int,int>> q;
    for(const auto &x : selectedVirus)
    {
        board[x.first][x.second] = 0; // 0초 시작
        q.push({x.first, x.second});
    }

    int cnt = 0;
    int maxTime = 0;
    while(!q.empty())
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << board[i][j] << ' ';
            } cout<<endl;
        }cout<<endl;

        cnt++;
        int r = q.front().first;
        int c = q.front().second;
        int time = board[r][c];
        maxTime = max(maxTime, time);
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(board[nr][nc] >= 0) continue; // 이미 바이러스 존재
            if(board[nr][nc] == WALL) continue;
            board[nr][nc] = time + 1;
            q.push({nr, nc});
        }
    }

    // 모든 곳 바이러스 감염 완료됨
    if(cnt == total)
    {
        return maxTime;
    }
    else return -1;
}

// M 개의 바이러스 위치 결정함
void dfs(int idx, int depth, vector<pair<int,int>> &virusPos, vector<pair<int,int>> &selectedVirus, vector<bool> &mark)
{
    // M개 찾음
    if(depth == M)
    {
        for(auto x : selectedVirus)
        {
            cout << "(" << x.first << ',' << x.second << ") ";
        } cout << endl;

        int res = StartVirus(selectedVirus);
        cout << "res: " << res << endl;
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
                total++;
                original_board[i][j] = EMPTY; // 바이러스 최초 위치
                virusPos.push_back({i,j});
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << original_board[i][j] << ' ';
        } cout << endl;
    } cout << endl;

    vector<pair<int,int>> selectedVirus;
    vector<bool> mark(M, false);
    dfs(0, 0, virusPos, selectedVirus, mark);
}