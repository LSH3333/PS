#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int answer;
int H, W;
char board[101][101];
vector<pair<int,int>> doors[26]; // 문 위치
vector<pair<int,int>> keys[26]; // 키들 위치

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Init()
{
    answer = 0;
    H = 0; W = 0;
    memset(board, 0, sizeof(board));
    for(int i = 0; i < 26; i++) doors[i].clear();
    for(int i = 0; i < 26; i++) keys[i].clear();
}

// 해당 입구에 들어가서 탐색, 문서 or 새로운 키 찾은 횟수 리턴
int bfs(const pair<int,int> &entry, vector<vector<bool>> &visited)
{
    int found = 0; // 문서 or 새로운 키 찾은 횟수
    queue<pair<int,int>> q;
    visited[entry.first][entry.second] = true;
    q.push({entry.first, entry.second});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // key 발견, 해당 키 없애고, 문 없앰
        if(board[r][c] >= 'a' && board[r][c] <= 'z')
        {
            for(auto pos : doors[toupper(board[r][c])-'A'])
            {
                board[pos.first][pos.second] = '.';
            }
            for(auto pos : keys[board[r][c]-'a'])
            {
                board[pos.first][pos.second] = '.';
            }

            found++;
            board[r][c] = '.';
        }
        // 문서 발견
        if(board[r][c] == '$')
        {
            answer++;
            found++;
            board[r][c] = '.';
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if(visited[nr][nc] || board[nr][nc] == '*') continue;
            // 다음 지점이 문이고, 해당 문에 대한 열쇠가 없는 경우
            if(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z') continue;
            q.push({nr,nc});
            visited[nr][nc] = true;
        }
    }

    return found;
}

void FindEntry(vector<pair<int,int>> &entry)
{
    for(int r = 0; r < H; r++)
    {
        for(int c = 0; c < W; c++)
        {
            if(r > 0 && r < H-1 && c > 0 && c < W-1) continue;
            // empty
            if(board[r][c] == '.') entry.push_back({r,c});
                // key
            else if(board[r][c] >= 'a' && board[r][c] <= 'z')
            {

                entry.push_back({r,c});
            }
            // doc
            else if(board[r][c] == '$') entry.push_back({r,c});
        }
    }
}

// 한번의 전체 탐색 수행
void StartSearch()
{
    while(true)
    {
        vector<pair<int,int>> entry;
        FindEntry(entry);
//        Print();
        int found = 0;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for(auto x : entry)
        {
//            cout << x.first << ',' << x.second << endl;
            if(visited[x.first][x.second]) continue;
            found += bfs(x, visited);
        }
        if(found == 0) break;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--)
    {
        Init();

        cin >> H >> W;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> board[i][j];

                // door
                if(board[i][j] >= 'A' && board[i][j] <= 'Z')
                {
                    doors[board[i][j]-'A'].push_back({i,j});
                }
                // key
                if(board[i][j] >= 'a' && board[i][j] <= 'z')
                {
                    keys[board[i][j]-'a'].push_back({i,j});
                }
            }
        }


        // 처음부터 갖고 있는 열쇠들에 대응하는 문들 다 없앰, 그 후 해당 키도 없앰
        string _owns; cin >> _owns;
        if(_owns != "0")
        {
            for(auto x : _owns)
            {
                for(auto pos : doors[toupper(x)-'A'])
                {
                    board[pos.first][pos.second] = '.';
                }
                for(auto pos : keys[x-'a'])
                {
                    board[pos.first][pos.second] = '.';
                }
            }
        }


        StartSearch();
        cout << answer << '\n';
    }
}