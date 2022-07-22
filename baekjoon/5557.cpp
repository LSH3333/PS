#include <iostream>
using namespace std;

int a[101];
long long d[21][101];
int N;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    d[a[0]][0] = 1;
    for(int c = 0; c < N; c++)
    {
        int next = a[c+1];
        for(int r = 0; r <= 20; r++)
        {
            if(r-next >= 0) d[r-next][c+1] += d[r][c];
            if(r+next <= 20) d[r+next][c+1] += d[r][c];
        }
    }
    
    cout << d[a[N-1]][N-2];
}