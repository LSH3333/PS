#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, D;
int enemy[20][20];
int original[20][20];

// left up right
int dr[] = {0, -1, 0};
int dc[] = {-1, 0, 1};

int cnt;

void CalTarget(int _c)
{
    // r, c, depth
    queue<pair<pair<int,int>,int>> q;
    q.push({{N, _c}, 1});

    // 거리 1인 칸
    if(enemy[N][_c] == 1)
    {
        enemy[N][_c] = 2;
        cnt++;
        return;
    }
    else if(enemy[N][_c] == 2)
    {
        return;
    }

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        if(depth >= D) break;

        for(int i = 0; i < 3; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nc < 0 || nc >= M) continue;

            if(enemy[nr][nc] == 1) // 아직 쓰러지지 않은 적
            {
                enemy[nr][nc] = 2;
                cnt++; return;
            }
            else if(enemy[nr][nc] == 2) // 다른 궁수가 이미 쓰러트린 적
            {
                return;
            }
            else // 적 없는 칸
            {
                q.push({{nr, nc}, depth+1});
            }
        }

    }
}

// 더이상 적 없으면 참 리턴
bool MoveEnemies()
{
    int enemyNum = 0;
    // 성벽에 도달한 적들
    for(int i = 0; i < M; i++)
    {
        enemy[N][i] = 0;
    }

    for(int i = N-1; i >= 0; i--)
    {
        for(int j = 0; j < M; j++)
        {
            if(enemy[i][j] == 0) continue;
            if(enemy[i][j] == 2) enemy[i][j] = 0;
            else if(enemy[i][j] == 1)
            {
                enemyNum++;
                enemy[i+1][j] = 1;
                enemy[i][j] = 0;
            }
        }
    }

    if(enemyNum == 0) return true;
    return false;
}

void Print()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << enemy[i][j] << ' ';
        }cout<<endl;
    }
}

void Copy()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            enemy[i][j] = original[i][j];
        }
    }
}

int main()
{
    cin >> N >> M >> D;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> original[i][j];
        }
    }
    Copy();

    int answer = 0;
    vector<int> archers(M);
    for(int i = 0; i < 3; i++) archers[i] = 1;
    do
    {
        cnt = 0;

        while(true)
        {
            for(int i = 0; i < M; i++)
            {
                if(archers[i] == 1)
                {
                    CalTarget(i);
                }
            }

            if(MoveEnemies()) break; // 더이상 적 없으면 참
        }

        answer = max(answer, cnt);
        Copy();
    } while(prev_permutation(archers.begin(), archers.end()));


    cout << answer;
}