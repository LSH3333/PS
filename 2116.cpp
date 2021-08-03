#include <iostream>
using namespace std;

int n;
int ans = 0;
int dice[10001][6];

int main()
{
    cin >> n;
    // i번째 면의 반대면 = (i+3) % 6
    // (0,3), (1,4), (2,5)가 서로 반대 면
    for (int i = 0; i < n; i++) {
        cin >> dice[i][0] >> dice[i][1] >> dice[i][2] >> dice[i][4] >> dice[i][5] >> dice[i][3];
    }

    // 첫번째 주사위의 아랫면이 dice[0][0]일때, dice[0][1]일때, ...
    for(int bottom = 0; bottom < 6; bottom++)
    {
        int bot_idx = bottom;
        int sum = 0;

        for(int cnt = 0; cnt < n; cnt++)
        {
            // 현재 주사위의 윗면의 인덱스
            int top_idx = (bot_idx+3)%6;
            int side_max = 0;
            // 옆면들중 가장 큰 수를 더함
            for(int i = 0; i < 6; i++)
            {
                if(i == bot_idx || i == top_idx) continue;
                side_max = max(side_max, dice[cnt][i]);
            }
            sum += side_max;

            // 다음 주사위의 아랫면을 찾는다, 현재 마지막 주사위라면 찾지 않는다
            if(cnt == n-1) continue;
            for(int i = 0; i < 6; i++)
            {
                // 현재 주사위의 윗면의 수가 다음 주사위의 아랫면의 수
                if(dice[cnt+1][i] == dice[cnt][top_idx])
                {
                    bot_idx = i;
                    break;
                }
            }
        }
        // 최댓값 갱신
        ans = max(ans, sum);
    }

    cout << ans;
}