#include <iostream>
#include <queue>
using namespace std;

int W, H;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<pair<int,int>> MoveFires(vector<vector<char>> &board, vector<pair<int,int>> &fires)
{
    vector<pair<int,int>> newFires;
    for(auto x : fires)
    {
        int r = x.first, c = x.second;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W || board[nr][nc] == '#' || board[nr][nc] == '*') continue;
            board[nr][nc] = '*';
            newFires.push_back({nr, nc});
        }
    }
    return newFires;
}

void Print(vector<vector<char>> &board)
{
    for(int r = 0; r < H; r++)
    {
        for(int c = 0; c < W; c++)
        {
            cout << board[r][c];
        }cout<<endl;
    }cout<<endl;
}

int bfs(vector<vector<char>> &board, pair<int,int> &person, vector<pair<int,int>> &fires)
{
    vector<vector<bool>> mark(H, vector<bool>(W, false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{person.first, person.second}, 0});
    mark[person.first][person.second] = true;

    int prevDepth = -1;
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(prevDepth != depth)
        {
            fires = MoveFires(board, fires);
            prevDepth = depth;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W)
            {
                return depth + 1;
            }
            if(board[nr][nc] == '#' || mark[nr][nc] || board[nr][nc] == '*') continue;
            q.push({{nr,nc}, depth+1});
            mark[nr][nc] = true;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--)
    {
        cin >> W >> H;
        vector<vector<char>> board(H, vector<char>(W));
        vector<pair<int,int>> fires; // 불들의 좌표
        pair<int,int> person; // 사람의 좌표
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == '*') fires.push_back({i,j});
                else if(board[i][j] == '@') { person = {i, j}; board[i][j] = '.'; }
            }
        }

        int res = bfs(board, person, fires);
        if(res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }

}