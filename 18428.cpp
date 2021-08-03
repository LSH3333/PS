#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int n;
char map[7][7];
vector<pair<int,int>> tl; // teacher's location
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool ans = false;

// 숨을수 있으면 true
bool CanHide()
{
    for(int t = 0; t < tl.size(); t++)
    {
        int tr = tl[t].first;
        int tc = tl[t].second;

        // 4방향 탐색
        for(int i = 0; i < 4; i++)
        {
            int _tr = tr + dr[i];
            int _tc = tc + dc[i];

            while(_tr >= 0 && _tr < n && _tc >= 0 && _tc < n)
            {
                // 시선경로에 벽이 있으면 더이상 탐색 불가능
                if(map[_tr][_tc] == 'O') break;
                // 학생을 찾음
                if(map[_tr][_tc] == 'S')
                {
                    return false;
                }

                _tr += dr[i];
                _tc += dc[i];
            }
        }
    }
    return true;
}

void MakeWalls(int depth)
{
    if(ans) return;

    if(depth == 3)
    {
        if(CanHide())
        {
            ans = true;
        }

        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 'T' || map[i][j] == 'S' || map[i][j] == 'O') continue;

            map[i][j] = 'O';
            MakeWalls(depth+1);
            map[i][j] = 'X';
        }
    }

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 'T')
                tl.push_back({i,j});
        }
    }

    MakeWalls(0);

    if(ans)
        cout << "YES";
    else
        cout << "NO";
}