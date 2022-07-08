#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000

int d[100010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0; i < 100010; i++) d[i] = MAX;
    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < N; i++)
    {
        int n; cin >> n;
        // 중복으로 주어질수 있음
        if(d[n] != 1)
        {
            d[n] = 1;
            v.push_back(n);
        }
    }
    sort(v.begin(), v.end());

    for(int i = 1; i <= K; i++)
    {
        if(d[i] == 1) continue;

        for(const auto &x : v)
        {
            if(i - x <= 0) break;
            d[i] = min(d[i], d[i-x]+1);
        }
    }

    if(d[K] == MAX) cout << -1;
    else cout << d[K];
}