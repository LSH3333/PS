#include <iostream>

using namespace std;
#define MAX 19

char map[21][21];
bool mark[21][21];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char winner = '0';
int curDir = 10;
int ans_r=0, ans_c=0;


int FindOpposite(int num)
{
    if(num < 4)
        return num+4;
    else
        return num-4;
}

void dfs(int r, int c, char cur, int depth, int dir)
{
    // 연속된 다섯알 발견
    if(depth == 4)
    {
        winner = cur;
        curDir = dir;
        ans_r = r+1;
        ans_c = c+1;
        // 여섯알 이상이 연속일수도 있으므로 리턴하지 않고 일단 진행한다
    }
    // 여섯알 이상이 연속인 경우
    if(depth == 5 && cur == winner)
    {
        // winner를 무효화 하고 리턴
        winner = '0';
        curDir = 10;
        ans_r = 0;
        ans_c = 0;
        return;
    }
    // 여섯번째가 연속은 아닌경우
    else if(depth == 5 && cur != winner)
    {
        return;
    }

    // 8방향 탐색
    for(int i = 0; i < 8; i++)
    {
        int _r = r + dr[i];
        int _c = c + dc[i];

        if(_r < 0 || _r >= MAX || _c < 0 || _c >= MAX) continue;

        // 탐색 첫부분은 방향은 상관이없다
        if(depth == 0)
            dir = i;
        // 이동지점이 현재 돌색과 같고 & 아직 방문 안했고 & 방향이 같다면
        if(map[_r][_c] == cur && !mark[_r][_c] && i == dir)
        {
            mark[_r][_c] = true;
            dfs(_r, _c, cur, depth+1, i);
            mark[_r][_c] = false;
        }

        // 5개의 연속된 돌 찾았음
        // 그런데 반대방향의 돌이 같은 색이라면 6개의 연속된 돌이 같은색이므로 무효
        if(depth==0 && winner == cur)
        {
            if(map[r+dr[FindOpposite(curDir)]][c+dc[FindOpposite(curDir)]] == winner)
            {
                winner = '0';
                curDir = 10;
            }
        }
    }

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
            // 1번돌 케이스
            if(map[i][j] == '1')
            {
                dfs(i, j, '1', 0, 0);
            }
            // 2번돌 케이스
            else if(map[i][j] == '2')
            {
                dfs(i, j, '2', 0, 0);
            }

            // 탐색후 winner가 확정되었다면
            if(winner != '0')
            {
                // 다섯번째 돌이 첫번째 돌보다 왼쪽에 있을경우 다섯번째 돌의 위치를 출력한다
                if(ans_c < j)
                {
                    cout << winner << '\n';
                    cout << ans_r << ' ' << ans_c;
                }
                // 그렇지 않으면 첫번째 돌의 위치를 출력한다
                else
                {
                    cout << winner << '\n';
                    cout << i+1 << ' ' << j+1;
                }

                return 0;
            }
        }
    }
    // 아직 승부가 결정되지 않음
    cout << '0';


}