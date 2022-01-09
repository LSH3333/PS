#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a[1010] = {0,}, d[1010] = {0,};
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    d[0]= 1;
    int answer = 1;
    for(int i = 1; i < n; i++)
    {
        int highest = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[i]) highest = max(highest, d[j]+1);
        }
        d[i] = highest;
        answer = max(answer, d[i]);
    }
//    for(int i = 0; i < n; i++) cout << d[i] << ' '; cout << endl;
    cout << answer;
}