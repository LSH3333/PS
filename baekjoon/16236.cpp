#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N;
int board[21][21];

struct Shark
{
    int size = 2;
    int r, c;
    int eatenFish = 0;
};

//void Print()
//{
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            cout << board[i][j] << ' ';
//        } cout << endl;
//    } cout << endl << endl;
//}

// babyShark에서 물고기까지 최단거리 구함
int bfs(int _r, int _c, Shark &babyShark)
{
    vector<vector<bool>> mark(N, vector<bool>(N, false));
    // r, c, depth
    queue<pair<pair<int,int>,int>> q;
    q.push({{babyShark.r, babyShark.c}, 0});
    mark[babyShark.r][babyShark.c] = true;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(r == _r && c == _c) // 물고기에 도착
        {
            return depth;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(mark[nr][nc]) continue;
            if(board[nr][nc] > babyShark.size) continue; // 아기상어보다 크면 지나갈수 없음
            q.push({{nr, nc}, depth+1});
            mark[nr][nc] = true;
        }
    }
    return 1000; // 도달 불가능
}

int main()
{
    int ans = 0;
    Shark babyShark = {2, 0, 0, 0};
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 9) { babyShark.r = i; babyShark.c = j; }
        }
    }


    while(true)
    {
        int nextR = 30, nextC = 30, distance = 1000;
        // 다음 먹을수 있는 물고기 탐색
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(board[i][j] != 0 && board[i][j] < babyShark.size)
                {
                    int nextDistance = bfs(i, j, babyShark);
                    if(nextDistance < distance)
                    {
                        nextR = i; nextC = j;
                        distance = nextDistance;
                    }
                }
            }
        }

        // 먹을수 있는 물고기가 없음
        if(nextR == 30) break;

        ans += distance; // 시간 추가

        board[nextR][nextC] = 0; // 해당 물고기 먹음
        babyShark.eatenFish++;
        if(babyShark.eatenFish == babyShark.size) { babyShark.size++; babyShark.eatenFish = 0;}
        // 아기상어 위치, 크기 갱신
        board[babyShark.r][babyShark.c] = 0;
        babyShark.r = nextR;
        babyShark.c = nextC;
    }

    cout << ans;

}