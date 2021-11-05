#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int d[100001];
    d[0] = 0;
    d[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        int smallest = 100001;
        int num = 1;
        while(i - num * num >= 0)
        {
            smallest = min(smallest, d[i-num*num]+1);
            num++;
        }

        d[i] = smallest;
    }

    cout << d[n];
}