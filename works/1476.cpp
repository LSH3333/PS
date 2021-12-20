#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int E,S,M;
    cin >> E >> S >> M;
    int cnt = 1;

    int e = 1, s = 1, m = 1;
    while(true)
    {
        if(e == E && s == S && m == M) break;
        cnt++;

        if(e < 15) e++;
        else e = 1;

        if(s < 28) s++;
        else s = 1;

        if(m < 19) m++;
        else m = 1;
    }
    cout << cnt;
}