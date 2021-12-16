#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


void Print(vector<string> board, int m, int n)
{
    cout << "PRINT: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    }
}

bool bfs(int r, int c,  vector<string> &board, vector<vector<bool>> &mark, int m, int n)
{
//    cout << "----------------------------------------" << endl;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0 ,1, 0, -1};

    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{r,c}, {-1, 0}});
    mark[r][c] = true;
    bool trigger = false;
    while(!q.empty())
    {
        int nr = q.front().first.first;
        int nc = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        // 알파벳인데 목표 알파벳이 아니라면 continue
        if(board[nr][nc] != '.' && board[nr][nc] != board[r][c]) continue;

//        cout << nr << ' ' << nc << ' ' << dir << ' ' << cnt << endl;
        if(trigger && board[nr][nc] == board[r][c])
        {
            if(cnt < 2)
            {
                board[nr][nc] = '.';
                board[r][c] = '.';
//                cout << "----------------------------------------" << endl;
                return true;
            }
        }
        else
            mark[nr][nc] = true;

        for(int i = 0; i < 4; i++)
        {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];
            if(nnr < 0 || nnr >= m || nnc < 0 || nnc >= n ) continue;
            if(board[nnr][nnc] == '*' || mark[nnr][nnc]) continue;

            // 방향이 다르다면
            if(dir != i && dir != -1)
            {
                q.push({{nnr, nnc}, {i, cnt+1}});
            }
            else
                q.push({{nnr, nnc}, {i, cnt}});

            trigger = true;
        }
    }
//    cout << "----------------------------------------" << endl;
    return false;
}


string solution(int m, int n, vector<string> board) {
    string answer = "";

    map<char, pair<int,int>> map;
    vector<char> v;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '.' || board[i][j] == '*') continue;
            v.push_back(board[i][j]);
            map[board[i][j]] = {i, j};
        }
    }
    // 정렬후 중복제거
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

//    for(auto x : v) cout << x << ' '; cout << endl;
//    Print(board, m, n);

    auto it = v.begin();
    while(!v.empty())
    {

//        cout << "target: " <<  *it << endl;
//        cout << "v: ";
//        for(auto x : v) cout << x << ' '; cout << endl;

        char target = *it;
        int r = map[target].first;
        int c = map[target].second;
//        cout << "r: " << r << ' ' << "c: " << c << endl;
//        cout << "answer: " << answer << endl;
        vector<vector<bool>> mark(110, vector<bool>(110, false));
        if(!bfs(r, c, board, mark, m, n))
        {
//            cout << "false" << endl;
            it++;
            if(it == v.end()) break;
        }
        else
        {
//            cout << "true" << endl;
            answer.push_back(*it);
            v.erase(it);
            it = v.begin(); // 여기?
        }
//        Print(board, m, n);
//        cout << endl;
    }
//    cout << "HERE" << endl;
    if(!v.empty()) return "IMPOSSIBLE";
    return answer;
}

int main()
{
    vector<string> board =
            {
                    ".ZI.",
                    "M.**",
                    "MZU.",
                    ".IU."
            };

    vector<string> board2 =
            {
                    "..I.",
                    "....",
                    "....",
                    ".I.."
            };
    vector<string> board3 =
            {
                    "DBA",
                    "C*A",
                    "CDB"
            };

    vector<string> board4 =
            {
                    "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE"
            };
    vector<string> board5 =
            {
                    "AB", "BA"
            };
    vector<string> board6 =
            {
                    "AA"
            };
    vector<string> board7 =
            {
                    "A..B",
                    "....",
                    "..BA"
            };

    vector<string> board8 =
            {
                    "A.B", "B.A", "C.C"
            };
    string ans = solution(4,4, board);
    cout << "sol:" << endl;
    cout << ans;
}