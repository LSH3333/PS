#include <iostream>
#include <vector>
using namespace std;

#define BUILD 1
#define DESTROY 2
int N, M, K;
int entry[100010], built[100010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    vector<vector<int>> edge(N+1);
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        entry[b]++;
        edge[a].push_back(b);
    }

    bool cheater = false;
    for(int i = 0; i < K; i++)
    {
        int mode, buildNum; cin >> mode >> buildNum;

        if(mode == BUILD)
        {
            // 건설 가능
            if(entry[buildNum] == 0)
            {
                built[buildNum]++;
                // 해당 건물이 최초로 지은 건물 이라면
                if(built[buildNum] == 1)
                {
                    for(auto x : edge[buildNum])
                    {
                        entry[x]--;
                    }
                }
            }
            else
            {
                cheater = true; break;
            }
        }
        else // DESTROY
        {
            // 파괴 가능
            if(built[buildNum] > 0)
            {
                built[buildNum]--;
                // 파괴 했는데 더이상 해당 건물이 존재하지 않는다면, 해당 건물이 필요한 건물들도 못 짓게됨 
                if(built[buildNum] == 0)
                {
                    for(auto x : edge[buildNum])
                    {
                        entry[x]++;
                    }
                }
            }
            else
            {
                cheater = true; break;
            }
        }
    }
    if(cheater) cout << "Lier!";
    else cout << "King-God-Emperor";

}