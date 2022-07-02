#include <iostream>
using namespace std;

// d[i]일이 끝났을떄 최대로 벌수 있는 돈
int d[1500002];
int T[1500002];
int P[1500002];


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= N; i++)
    {
        int day = T[i];
        if(i+day-1 <= N)
            d[i+day-1] = max(d[i-1] + P[i], d[i+day-1]);
        d[i] = max(d[i], d[i-1]);
    }
    cout << d[N];

}