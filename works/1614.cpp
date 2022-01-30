#include <iostream>
using namespace std;

int main()
{
    long long finger, num;
    cin >> finger >> num;
    long long ans = 0;
    long long goAndReturn;

    if(finger == 1)
    {
        // 왕복할수 있는 횟수
        goAndReturn = num - 1;
        ans = 1 + (8 * goAndReturn);
        ans += 7;
    }
    else if(finger == 5)
    {
        goAndReturn = num;
        ans = 1 + (8 * goAndReturn);
        ans += 3;
    }
    else
    {
        goAndReturn = num / 2;
        ans = 1 + (8 * goAndReturn);
        if(num % 2 == 0)
        {
            ans += finger-2;
        }
        else
        {
            ans += 7 - finger + 1;
        }
    }
    cout << ans;
}