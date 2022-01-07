#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<string> board;
int M,N;


bool bfs(int _r, int _c)
{
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // {r,c}, {dir, bent}
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{_r, _c}, {-1,0}});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int bent = q.front().second.second;
        q.pop();
//        cout << r << ' ' << c << ' ' << dir << ' ' << bent << endl;
        for(int i = 0; i < 4; i++)
        {
            // 반대 방향으로는 가지 않는다
            if(dir != -1 && abs(dir-i)==2) continue;
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if(board[nr][nc] == '*') continue;
            if(board[nr][nc] != '.' && board[nr][nc] != board[_r][_c]) continue;
//            cout << "in: " << nr << ' ' << nc << ' ' << i << ' ' << bent << endl;

            int nbent = bent;
            if(dir != -1 && dir != i) nbent++;
            if(nbent > 1) continue;
            q.push({{nr,nc}, {i, nbent}});

            if(board[nr][nc] == board[_r][_c])
            {
                board[_r][_c] = '.';
                board[nr][nc] = '.';
                return true;
            }


        }
    }
    return false;
}

string solution(int m, int n, vector<string> _board)
{
    string answer = "";
    M = m; N = n;
    board = _board;
    map<char, pair<int,int>> map;

    string tmp = "";
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] != '.' && board[i][j] != '*')
            {
                map[board[i][j]] = {i,j};
                tmp += board[i][j];
            }
        }
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());
    bool impos = false;
    vector<bool> mark(tmp.size(), false);
    while(true)
    {
        bool possible = false;
        for(int i = 0; i < tmp.size(); i++)
        {
            if(mark[i]) continue;
            if(bfs(map[tmp[i]].first, map[tmp[i]].second))
            {
                answer += tmp[i];
                mark[i] = true;
                possible = true;
                break;
            }
        }
        if(!possible) { impos = true; break; }
        if(answer.size() == tmp.size()) {impos = false; break;}
    }

    if(impos) answer = "IMPOSSIBLE";
    return answer;
}