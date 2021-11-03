#include <iostream>
using namespace std;

int main()
{
    //int a = 1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18;
    //cout << a;

    long long n;
    cin >> n;
    long long sum = 0;
    int cnt;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
        if(n-sum <= i)
        {
            cnt = i;
            break;
        }
    }
    cout << cnt;
}