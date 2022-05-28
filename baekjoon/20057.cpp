#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[510][510];

vector<pair<int,int>> CalPos()
{
    // right, down, left, up
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    bool mark[510][510] = {false,};
    vector<pair<int,int>> path;

    int r = 1, c = 1, dir = 0;
    while(true)
    {
        mark[r][c] = true;
        path.push_back({r,c});
        if(r == N/2+1 && c == N/2+1) break;
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 1 || nr > N || nc < 1 || nc > N || mark[nr][nc])
        {
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr; c = nc;
    }

    reverse(path.begin(), path.end());
    return path;
}

vector<int> CalDir()
{
    int dir = 0, cnt = 0, dirCnt = 1;
    vector<int> dirs;
    while(cnt < N*N)
    {
        for(int i = 0; i < dirCnt; i++)
        {
            dirs.push_back(dir);
            cnt++;
        }
        if(cnt >= N*N) break;
        dir = (dir + 1) % 4;
        for(int i = 0; i < dirCnt; i++)
        {
            dirs.push_back(dir);
            cnt++;
        }
        dirCnt++;
        dir = (dir + 1) % 4;
    }

    return dirs;
}


// dir: left(0), down(1), right(2), up(3)
// 모래가 흩날려 도착하는 좌표 지점들 리턴
vector<pair<pair<int,int>,int>> Cal(int r, int c, int dir)
{
    int dr[4], dc[4];
    if(dir == 0) // left
    {
        // up, right, down, left
        dr[0] = -1; dr[1] = 0; dr[2] = 1; dr[3] = 0;
        dc[0] = 0; dc[1] = 1; dc[2] = 0; dc[3] = -1;
    }
    else if(dir == 1) // down
    {
        // left, up, right, down
        dr[0] = 0; dr[1] = -1; dr[2] = 0; dr[3] = 1;
        dc[0] = -1; dc[1] = 0; dc[2] = 1; dc[3] = 0;
    }
    else if(dir == 2) // right
    {
        // up, left, down, right
        dr[0] = -1; dr[1] = 0; dr[2] = 1; dr[3] = 0;
        dc[0] = 0; dc[1] = -1; dc[2] = 0; dc[3] = 1;
    }
    else if(dir == 3) // up
    {
        // right, down, left, up
        dr[0] = 0; dr[1] = 1; dr[2] = 0; dr[3] = -1;
        dc[0] = 1; dc[1] = 0; dc[2] = -1; dc[3] = 0;
    }
    int nr = r + dr[3];
    int nc = c + dc[3];
    int alphaR = nr + dr[3];
    int alphaC = nc + dc[3];

    // r, c, %
    vector<pair<pair<int,int>, int>> pos;

    // alpha
    pos.push_back({{alphaR, alphaC}, 0});
    // y
    pos.push_back({{nr, nc}, 0});

    // 2%
    pos.push_back({{nr + dr[0] * 2, nc + dc[0] * 2}, 2});
    // 10%
    pos.push_back({{alphaR + dr[0], alphaC + dc[0]}, 10});
    // 7%
    pos.push_back({{nr + dr[0], nc + dc[0]}, 7});
    // 1%
    pos.push_back({{r + dr[0], c + dc[0]}, 1});
    // 5%
    pos.push_back({{alphaR + dr[3], alphaC + dc[3]}, 5});
    // 10%
    pos.push_back({{alphaR + dr[2], alphaC + dc[2]}, 10});
    // 7%
    pos.push_back({{nr + dr[2], nc + dc[2]}, 7});
    // 1%
    pos.push_back({{r + dr[2], c + dc[2]}, 1});
    // 2%
    pos.push_back({{nr + dr[2] * 2, nc + dc[2] * 2}, 2});

//    for(auto x : pos) cout << x.first << ',' << x.second << endl;
    return pos;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<pair<int,int>> paths = CalPos(); // 좌표
    vector<int> directions = CalDir(); // 방향

//    for(int i = 0; i < N*N; i++)
//    {
//        cout << paths[i].first << ',' << paths[i].second << ": ";
//        cout << directions[i] << endl;
//    }

    int answer = 0;
    for(int i = 0; i < N*N; i++)
    {
        vector<pair<pair<int,int>,int>> pos = Cal(paths[i].first, paths[i].second, directions[i]);
        int aR = pos[0].first.first, aC = pos[0].first.second; // alpha
        int yR = pos[1].first.first, yC = pos[1].first.second; // y
        int sand = A[yR][yC]; // y좌표의 모래양
        int movedSand = 0; // 이동한 모래 양

        for(int j = 2; j < pos.size(); j++)
        {
            int r = pos[j].first.first; int c = pos[j].first.second;
            int perc = pos[j].second;
            int move = (sand / 100 * perc);

            if(r < 1 || r > N || c < 1 || c > N) // 범위 벗어남
            {
                answer += move;
            }
            else
            {
                A[r][c] += move;
            }
            movedSand += move;
        }

        A[aR][aC] += sand - movedSand;
    }

    cout << answer;
}