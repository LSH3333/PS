#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int limit[3];
int bottle[3];

void dfs(int bot)
{
    for(int i = 0; i < 3; i++)
    {
        // 물통이 비어있음
        if(bottle[i] == 0) continue;

        for(int j = 0; j < 3; j++)
        {
            // 물을 부을 물통이 이미 가득 차있음
            if(bottle[j] == limit[j]) continue;
            int toPour = limit[j] - bottle[j];
            // 물을 부을 물통을 꽉 채울만틈 현재 물통에 물이 있음
            if(bottle[i] - toPour >= 0)
            {
                bottle[i] -= toPour;
                bottle[j] += toPour;
            }
            // 물을 부을 물통을 꽉 채울만큼 현재 물통에 물이 없음
            else
            {
                bottle[j] = bottle[i];
                bottle[i] = 0;
            }
            dfs(j);

            // 복구필요 
        }
    }
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    limit[0] = A; limit[1] = B; limit[2] = C;
    bottle[0] = 0; bottle[1] = 0; bottle[2] = C;
}