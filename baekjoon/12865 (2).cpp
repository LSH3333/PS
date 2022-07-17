#include <iostream>
using namespace std;

int W[102]; // 물건들의 무게
int V[102]; // 물건들의 가치
int d[102][100001];
int N, K;


int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int w, v; cin >> w >> v;
        W[i] = w; V[i] = v;
    }

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            // i번째 물건 넣을 경우, 안넣을 경우
            if(W[i] <= j) d[i][j] = max(d[i-1][j], V[i] + d[i-1][j-W[i]]);
            else d[i][j] = d[i-1][j];
            answer = max(answer ,d[i][j]);
        }
    }

    cout << answer;
}