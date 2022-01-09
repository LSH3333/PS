#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a[1010] = {0,}, d[1010] = {0,};
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) {cout << 0; return 0;}

    d[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int lowest = 2000000000;
        bool trigger = false;
        for(int j = 0; j < i; j++)
        {
            if(j + a[j] >= i) { lowest = min(lowest, d[j]+1); trigger = true; }
        }
        if(!trigger) { cout << -1; return 0; }
        d[i] = lowest;
    }

//    for(int i = 0; i < n; i++) cout << d[i] << ' '; cout << endl;

//    int answer = d[n-1] == 0 ? -1 : d[n-1];
    cout << d[n-1];
}