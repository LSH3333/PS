#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int num = 1;
    int cnt = 0;
    while(num <= n)
    {
        cnt += (n - num + 1);
        num *= 10;
    }
    cout << cnt;
}