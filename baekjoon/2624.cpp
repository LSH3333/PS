#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[101][10001];
int coin[101]; // 동전의 종류
int coinNum[101]; // 동전의 갯수

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, K; cin >> T >> K;
    vector<pair<int,int>> v(K);
    for(int i = 0; i < K; i++)
    {
        int n, p; cin >> n >> p;
        v[i] = {n, p};
    }
    sort(v.begin(), v.end(), greater<>());


    for(int i = 0; i < K; i++)
    {
        coin[i] = v[i].first;
        coinNum[i] = v[i].second;
        d[i][coin[i]] = 1;
    }

    for(int i = 1; i <= T; i++)
    {
        for(int j = 0; j < K; j++)
        {
            int c = coin[j];
            if(i-c <= 0) continue;

            for(int k = 0; k <= j; k++)
            {
                d[j][i] += d[k][i-c];
            }

            if((i-c) / c == coinNum[j]) d[j][i]--;
        }
    }

    int answer = 0;
    for(int i = 0; i < K; i++) answer += d[i][T];
    cout << answer;

//    for(int r = 0; r < K; r++)
//    {
//        for(int c = 1 ; c <= T; c++)
//        {
//            cout << d[r][c] << ' ';
//        } cout << endl;
//    }
}