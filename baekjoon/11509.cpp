#include <iostream>
#define MAX 1000001
using namespace std;

int n;
int balloon[MAX];
int mark[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> balloon[i];

    for(int i = 0; i < n; i++)
    {
        int h = balloon[i];

        if(mark[h+1] > 0)
        {
            mark[h+1]--;
            mark[h]++;
        }
        else
        {
            mark[h]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += mark[i];
    }

    cout << ans;
}