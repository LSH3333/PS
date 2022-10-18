#include <iostream>
using namespace std;

#define INF 1000000000

int N;
pair<int,int> arr[510];
int d[510][510];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 1; i < N; i++) // 크기
    {
        for(int j = 1; j+i <= N; j++) // 시작 인덱스
        {
            d[j][j+i] = INF;
            for(int k = j; k < j+i; k++)
            {
                d[j][j+i] = min(d[j][j+i], d[j][k] + d[k+1][i+j] + (arr[j].first * arr[k].second * arr[j+i].second));
            }
        }
    }

    cout << d[1][N];
}