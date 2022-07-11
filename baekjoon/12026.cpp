#include <iostream>
using namespace std;

char arr[1010];
int d[1010];
#define INF 1000000000

char FindBefore(char c)
{
    if(c == 'B') return 'J';
    else if(c == 'O') return 'B';
    else return 'O';
}

int main()
{
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
    {
        char c; cin >> c;
        arr[i] = c;
        d[i] = INF;
    }

    d[0] = 0; d[1] = 0;

    for(int i = 2; i <= N; i++)
    {
        char target = FindBefore(arr[i]);

        for(int j = i-1; j >= 1; j--)
        {
            if(arr[j] == target)
            {
                d[i] = min(d[i], d[j] + (j - i) * (j - i));
            }
        }
    }

    if(d[N] == INF) cout << -1;
    else cout << d[N];
}