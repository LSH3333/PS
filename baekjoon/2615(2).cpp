#include <iostream>
using namespace std;
#define MAX 19

int map[21][21];
bool mark[21][21][4];

// 좌측상단 돌 위치를 출력하기 위해 8방향이 아닌 4방향 :남, 남동, 동, 북동 만 탐색한다
int dr[4] = {1, 1, 0, -1};
int dc[4] = {0, 1, 1, 1};

// map[r][c]에서 dir 방향으로 탐색해서 map[r][c]와 같은 색의 돌이 몇개 이어져있는지 리턴한다
int dfs(int r, int c, int dir, int stone)
{
    // 돌 색이 다르다면 0 리턴
    if(map[r][c] != stone)
        return 0;

    int cnt = 1;
    // 위치, 방향까지 기억해서 방문여부 확인
    mark[r][c][dir] = true;

    int _r = r + dr[dir];
    int _c = c + dc[dir];

    cnt += dfs(_r, _c, dir, stone);

    return cnt;
}

int main()
{
    // input
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            cin >> map[i][j];
        }
    }


    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            // 가장왼위에 있는 바둑알의 위치를 출력해야하므로 좌측상단에서 아래로 내려가는 방향으로 탐색해야한다
            if(map[j][i] == 0) continue;
            for(int k = 0; k < 4; k++)
            {
                // 이미 방문한 방향이면 계산하지 않음
                if(mark[j][i][k]) continue;
                // 탐색했는데 5개의 돌이 연속이라면
                if(dfs(j, i, k, map[j][i]) == 5)
                {
                    cout << map[j][i] << '\n';
                    cout << j+1 << ' ' << i+1 << '\n';
                    return 0;
                }
            }
        }
    }
    // 아직 아무도 이기지 못한 상태
    cout << 0;
}