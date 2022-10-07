#include <iostream>
#include <cstring>
using namespace std;

int a[1010];
int d[1010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        for(int i = 0; i < N; i++) cin >> a[i];

        d[0] = a[0];
        int answer = d[0];
        for(int i = 1; i < N; i++)
        {
            d[i] = max(d[i-1] + a[i], a[i]);
            answer = max(answer, d[i]);
        }
        cout << answer << '\n';
    }

}