#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a[1010] = {0,}, d[1010] = {0,};
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    d[0] = a[0];
    int answer = d[0];
    for(int i = 1; i < n; i++)
    {
        int highest = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i]) highest = max(highest, d[j]);
        }
        d[i] = highest + a[i];
        answer = max(answer, d[i]);
    }

    cout << answer;
}