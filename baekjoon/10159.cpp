#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool d[110][110];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        d[a][b] = true;
    }

    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(d[i][k] && d[k][j]) d[i][j] = true;
            }
        }
    }

    for(int node = 1; node <= N; node++)
    {
        int sum = 0;
        for(int i = 1; i <= N; i++)
        {
            sum += d[node][i];
            sum += d[i][node];
        }
        cout << N - (1 + sum) << '\n';
    }

}