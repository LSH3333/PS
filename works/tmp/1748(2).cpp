#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;

    int len = 1;
    int val = n;
    int cnt = 0;
    int num = 1;

    while(val > 0)
    {
        if(val / 10 == 0)
        {
            cnt += (n - len + 1) * num;
            break;
        }
        else
        {
            cnt += 9 * len * num;
            len *= 10;
            num++;
            val /= 10;
        }
    }
    cout << cnt;
}