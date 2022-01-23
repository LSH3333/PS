#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// A B C의 한계치
int limit[3];
// A B C가 현재 담고있는 물의 양
int bottle[3];
// 세가지의 물병에 담긴 물의 양 기록
bool mark[210][210][210];
vector<int> answer;

void dfs(int from)
{
//    cout << bottle[0] << ' ' << bottle[1] << ' ' << bottle[2] << endl;
    if(bottle[0] == 0) answer.push_back(bottle[2]);

    for(int i = 0; i < 3; i++)
    {
        // 물통이 비어있음
        if(bottle[i] == 0) continue;

        for(int j = 0; j < 3; j++)
        {
            // 나자신에는 붓지 않음
            if(i == j) continue;
            // 물을 부을 물통이 이미 가득 차있음
            if(bottle[j] == limit[j]) continue;
            int toPour = limit[j] - bottle[j];
            // 물을 붓기전 물통들의 물의 양
            int i_before = bottle[i], j_before = bottle[j];

            // 물을 부을 물통을 꽉 채울만틈 현재 물통에 물이 있음
            if(bottle[i] - toPour >= 0)
            {
                bottle[i] -= toPour;
                bottle[j] += toPour;
            }
            // 물을 부을 물통을 꽉 채울만큼 현재 물통에 물이 없음
            else
            {
                bottle[j] = bottle[i] + bottle[j];
                bottle[i] = 0;
            }
            // 계산한 각 물통들의 물의 양이 이미 방문했던 양이라면 되돌리고 dfs 진행하지않음
            if(mark[bottle[0]][bottle[1]][bottle[2]])
            {
                // 물의 양 복구
                bottle[i] = i_before;
                bottle[j] = j_before;
                continue;
            }
            mark[bottle[0]][bottle[1]][bottle[2]] = true;
            dfs(i);
            mark[bottle[0]][bottle[1]][bottle[2]] = false;
            // 물의 양 복구
            bottle[i] = i_before;
            bottle[j] = j_before;
        }
    }
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    limit[0] = A; limit[1] = B; limit[2] = C;
    bottle[0] = 0; bottle[1] = 0; bottle[2] = C;
    mark[0][0][C] = true;
    dfs(-1);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for(auto x : answer)  cout << x << ' ';
}