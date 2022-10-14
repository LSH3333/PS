#include <iostream>
using namespace std;

int d[1000001];

int main()
{
    int n;
    cin >> n;

    d[0] = 0;
    d[1] = 0;

    for(int i = 2; i <= n; i++)
    {
        int num = d[i-1] + 1;
        if(i % 2 == 0) num = min(d[i/2] + 1, num);
        if(i % 3 == 0) num = min(d[i/3] + 1, num);

        d[i] = num;
    }

    cout << d[n];
}