#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
// d[i][j] : j분에 i에 도착할수 있는 경우의수
long long d[8][100001];

void MakeEdge(vector<int> edge[])
{
    edge[0].push_back(1); edge[0].push_back(2);
    edge[1].push_back(0); edge[1].push_back(2); edge[1].push_back(3);
    edge[2].push_back(0); edge[2].push_back(1); edge[2].push_back(3); edge[2].push_back(7);
    edge[3].push_back(1); edge[3].push_back(2); edge[3].push_back(4); edge[3].push_back(7);
    edge[4].push_back(3); edge[4].push_back(5); edge[4].push_back(7);
    edge[5].push_back(4); edge[5].push_back(6);
    edge[6].push_back(5); edge[6].push_back(7);
    edge[7].push_back(2); edge[7].push_back(3); edge[7].push_back(4); edge[7].push_back(6);
}

int main()
{
    int D; cin >> D;
    d[1][1] = 1;
    d[2][1] = 1;

    // 인접 장소
    vector<int> edge[8];
    MakeEdge(edge);

    for(int i = 2; i <= D; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            long long sum = 0;
            for(auto x : edge[j]) sum += d[x][i-1] % MOD;
            d[j][i] = sum % MOD;
        }
    }

    cout << d[0][D] % MOD;
}