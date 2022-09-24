#include <iostream>
#include <vector>
using namespace std;

int N, K, S;
vector<int> edges[410];
bool d[410][410];

void FloydWarshall()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(d[i][k] && d[k][j])
                {
                    d[i][j] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        d[a][b] = true;
    }

    FloydWarshall();

    cin >> S;
    for(int i = 0; i < S; i++)
    {
        int a, b; cin >> a >> b;

        if(!d[a][b] && !d[b][a]) cout << 0 << '\n';
        else if(d[a][b] && !d[b][a]) cout << -1 << '\n';
        else cout << 1 << '\n';
    }

}