#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mark[2000010];

int main()
{
    int n, c; cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        for(int j = num; j <= c; j += num) mark[j] = true;
    }

    int cnt = 0;
    for(int i = 0; i <= c; i++)
    {
        if(mark[i]) cnt++;
    }

    cout << cnt;
}