#include <iostream>
#include <vector>
#define INF 100000000
#define MAX 210
using namespace std;

int arr[MAX][MAX] = {INF, };
int d[MAX][MAX];

void FloydWarshall(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            d[i][j] = arr[i][j];
        }
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 999999999;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    for(int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        arr[start][end] = cost;
        arr[end][start] = cost;
    }

    FloydWarshall(n);

    for(int i = 1; i <= n; i++)
    {
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    cout << answer;
    return answer;
}