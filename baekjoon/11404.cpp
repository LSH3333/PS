#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N, M;
int arr[110][110];

void FloydWarshall()
{
    for(int k = 1; k <= N; k++) // 거쳐 가는 도시
    {
        for(int i = 1; i <= N; i++) // 출발 도시
        {
            for(int j = 1; j <= N; j++) // 도착 도시
            {
                if(arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            if(i == j) { arr[i][j] = 0; continue; }
            arr[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        if(arr[a][b] > c)
        {
            arr[a][b] = c;
        }
    }

    FloydWarshall();

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(arr[i][j] == INF) cout << 0 << ' ';
            else cout << arr[i][j] << ' ';
        } cout << endl;
    }

}