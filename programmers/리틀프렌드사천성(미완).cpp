#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> board;

bool bfs(int r, int c, int m, int n)
{

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0 ,1, 0, -1};

    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{r,c}, {-1, 0}});

    while(!q.empty())
    {
        int nr = q.front().first.first;
        int nc = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();


        for(int i = 0; i < 4; i++)
        {
            // 반대로 갈 필요는 없다
            if(dir != -1 && abs(dir-i) == 2) continue;
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];
            // 방향이 다르다 = 꺾은 횟수 + 1
            int ncnt = (dir == i || dir == -1) ? cnt : cnt + 1;
            // 범위
            if(nnr < 0 || nnr >= m || nnc < 0 || nnc >= n) continue;

            if(ncnt > 1) continue;
            if(board[nnr][nnc] == '*') continue;
            if(board[nnr][nnc] == '.') q.push({{nnr,nnc},{i, ncnt}});
            else if(board[nnr][nnc] == board[r][c])
            {
                board[r][c] = '.';
                board[nnr][nnc] = '.';
                return true;
            }
        }

    }

    return false;
}


string solution(int m, int n, vector<string> _board) {
    string answer = "";
    board = _board;
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

    bool impos = false;
    vector<bool> v_mark(v.size(), false);

    while(true)
    {
        bool success = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(v_mark[i]) continue;
            char target = v[i];
            int r = map[target].first;
            int c = map[target].second;

            if(bfs(r, c, m, n))
            {
                v_mark[i] = true;
                answer.push_back(target);
                success = true;
                break;
            }
        }
        // 타일 제거 불가
        if(!success) { impos = true; break; }
        if(answer.size() == v.size()) { impos = false; break; }
    }

    if(impos) return "IMPOSSIBLE";
    return answer;
}
