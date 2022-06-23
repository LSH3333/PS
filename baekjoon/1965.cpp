#include <iostream>
using namespace std;

int a[1010];
int d[1010];

int main()
{
    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    d[0] = 1;
    for(int i = 1; i < n; i++)
    {
        int val = 0;
        for(int j = i-1; j >= 0; j--)
        {
            if(a[j] < a[i])
            {
                val = max(val, d[j]);
            }
        }
        d[i] = val+1;
    }

    int answer = 0;
    for(int i = 0; i < n; i++) answer = max(answer, d[i]);
    cout << answer;
}