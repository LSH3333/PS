#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Print(vector<string> &v)
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j <12; j++)
        {
            cout << v[i][j];
        } cout << endl;
    }cout<<endl;
}

// 하나의 칸에 대하여 같은 색 뿌요가 4개 이상 연결되어 있다면 터트려 '.' 으로 만듦
// 터트린 뿌요 갯수 리턴
int bfs(vector<string> &v, int _r, int _c)
{
    int cnt = 1;
    char target = v[_r][_c];

    vector<vector<bool>> mark(6, vector<bool>(12,false));
    queue<pair<int,int>> q;
    mark[_r][_c] = true;
    q.push({_r,_c});

    vector<pair<int,int>> puyoList;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        puyoList.push_back({r,c});

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= 6 || nc < 0 || nc >= 12) continue;
            if(mark[nr][nc] || v[nr][nc] != target) continue;
            cnt++;
            mark[nr][nc] = true;
            q.push({nr,nc});
        }
    }

    // 4개 이상이면 터짐
    if(cnt >= 4)
    {
        for(auto &x : puyoList)
        {
            v[x.first][x.second] = '.';
        }
    }

    if(cnt < 4) return 0;
    else return cnt;
}

// 모든 칸 탐색
// 터트린 뿌요 없다면 false 반환
bool Puyo(vector<string> &v)
{
    int cnt = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(v[i][j] == '.') continue;
            cnt += bfs(v, i, j);
        }
    }

    if(cnt == 0) return false;
    return true;
}

// 터트린후 뿌요들 아래로 내려옴
void Move(vector<string> &v)
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 11; j >= 0; j--)
        {
            if(v[i][j] == '.') v[i].erase(j,1);
        }
    }


    for(int i = 0; i < 6; i++)
    {
        while(v[i].size() < 12) v[i].push_back('.');
    }
}



int main()
{
    vector<string> inputs;
    for(int i = 0; i < 12; i++)
    {
        string str; cin >> str;
        inputs.push_back(str);
    }

    vector<string> v;
    for(int c = 0; c < 6; c++)
    {
        string str;
        for(int r = 11; r >= 0; r--)
        {
            str.push_back(inputs[r][c]);
        }
        v.push_back(str);
    }


    int answer = 0;
    while(Puyo(v))
    {
        answer++;
        Move(v);
    }
    cout << answer;
}