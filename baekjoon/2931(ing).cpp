#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int cnt;

void Print(vector<vector<int>> &board)
{
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            printf("%2d ", board[i][j]);
        } cout << endl;
    }
}

vector<vector<int>> road[8] =
        {
                {},
                {{}, {6,7,3,4}, {5,7,2,3}, {}}, // '1'
                {{5,7,1,4}, {6,7,3,4},{},{}}, // '2'
                {{5,7,1,4}, {}, {}, {6,7,1,2}}, // '3'
                {{}, {}, {5,7,2,3}, {6,7,1,2}}, // '4'
                {{5,7,1,4}, {}, {5,7,2,3}, {}}, // '|',
                {{}, {6,7,3,4}, {}, {6,7,1,2}}, // '-'
                {{5,7,1,4}, {6,7,3,4}, {5,7,2,3}, {6,7,1,2}}
        };

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0 ,-1};
vector<pair<int,int>> v;

// 현재 블록 cur과 방향 dir를 토대로 다음 블록 next로 이동 가능한지 판단
bool Check(int cur, int dir, int next)
{
    if(road[cur][dir].empty()) return false;
    for(int i = 0; i < road[cur][dir].size(); i++)
    {
        if(road[cur][dir][i] == next) return true;
    }
    return false;
}

bool CheckAllVisited(const vector<vector<int>> &board, const vector<vector<int>> &mark)
{
    for(auto x : v)
    {
        int r = x.first; int c = x.second;
        if(board[r][c] == 7 && mark[r][c] < 2) return false;
        else if(board[r][c] != 7 && mark[r][c] == 0) return false;
    }
    return true;
}

// Z 방문 가능하면 return true else false
bool bfs(int MR, int MC, int goalR, int goalC, const vector<vector<int>> &board)
{
    vector<vector<int>> mark(R+1, vector<int>(C+1, 0));
    // {r,c},dir
    queue<pair<pair<int,int>,int>> q;
    mark[MR][MC]++;
    q.push({{MR, MC}, -1});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        cout << r << ',' << c << "   ";
        // 현재 블록이 십자 블록이라면
        if(board[r][c] == 7)
        {
            // 같은 방향으로만 이동 가능
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if(board[nr][nc] == 0) continue;
            // 다음 블록이 십자 블록이고 2번 방문했다면 이동 불가
            if(board[nr][nc] == 7 && mark[nr][nc] >= 2) continue;
            // 십자 블록 이외에는 단 한번만 방문 가능
            if(board[nr][nc] != 7 && mark[nr][nc] > 0) continue;
            // 다음 블록과 안맞음
            if(!Check(board[r][c], dir, board[nr][nc])) continue;
            if(nr == goalR && nc == goalC) // 목적지
            {
                cnt--;
                if(cnt == 0 && CheckAllVisited(board,mark)) return true;
            }

            mark[nr][nc]++;
            q.push({{nr,nc}, dir});
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            if(dir != -1 && i == (dir+2)%4) continue; // 왔던 방향으로는 가지 않음
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if(board[nr][nc] == 0) continue;
            // 다음 블록이 십자 블록이고 2번 방문했다면 이동 불가
            if(board[nr][nc] == 7 && mark[nr][nc] >= 2) continue;
            // 십자 블록 이외에는 단 한번만 방문 가능
            if(board[nr][nc] != 7 && mark[nr][nc] > 0) continue;
            // 다음 블록과 안맞음
            if(board[r][c] != -1 && !Check(board[r][c], i, board[nr][nc])) continue;
            if(nr == goalR && nc == goalC) // 목적지
            {
                cnt--;
                if(cnt == 0 && CheckAllVisited(board, mark)) return true;
            }

            mark[nr][nc]++;
            q.push({{nr,nc}, i});
            break;
        }
    } cout<<endl;
    return false;
}



int main()
{
    cin >> R >> C;
    vector<vector<int>> board(R+1, vector<int>(C+1));
    int MR, MC, ZR, ZC;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            char c; cin >> c;
            if(c == '.') board[i][j] = 0;
            else if(c == '|') { board[i][j] = 5; v.push_back({i,j}); }
            else if(c == '-') { board[i][j] = 6; v.push_back({i,j});}
            else if(c == '+') { board[i][j] = 7; v.push_back({i,j});}
            else if(c == 'M') { board[i][j] = -1; MR = i; MC = j; }
            else if(c == 'Z') { board[i][j] = -2; ZR = i; ZC = j; }
            else { board[i][j] = c-'0'; v.push_back({i,j});}
        }
    }

    int goalR, goalC;
    // Z의 인접 블록 찾음
    for(int i = 0; i < 4; i++)
    {
        int nr = ZR + dr[i];
        int nc = ZC + dc[i];
        if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if(board[nr][nc] == 0) continue;
        if(Check(7, i, board[nr][nc]))
        {
            goalR = nr; goalC = nc;
            if(board[nr][nc] == 7) cnt = 2; else cnt = 1;
            break;
        }
    }

    for(int r = 1; r <= R; r++)
    {
        for(int c = 1; c <= C; c++)
        {
            if(board[r][c] != 0) continue;
            cout << "---------" << r << ',' << c << endl;
            for(int i = 1; i <= 7; i++)
            {
                board[r][c] = i; // 도로 건설
                cout << "road: " << i << endl;
                if(bfs(MR, MC, goalR, goalC, board))
                {
                    char tmp;
                    if(i == 5) tmp = '|';
                    else if(i == 6) tmp = '-';
                    else if(i == 7) tmp = '+';
                    else tmp = (char)(i+'0');
                    cout << r << ' ' << c << ' ' << tmp;
                    return 0;
                }
                board[r][c] = 0; // 복구
            }
        }
    }


}