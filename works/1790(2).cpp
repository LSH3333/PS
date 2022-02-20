#include <iostream>
#include <cmath>
using namespace std;

int len(int n)
{
    int res = 0;
    while(n) { res++; n /= 10; }
    return res;
}

int getlength(int n)
{
    int length = len(n);
    int i, m = 1, res = 0;
    for(i = 1; i < length; i++)
    {
        res += 9 * m * i;
        m *= 10;
    }
    res += (n - m + 1) * i;
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    if(getlength(n) < k) cout << -1;
    else
    {
        // l: 전개되는 숫자의 자릿수
        // m: 1, 10, 100, 1000 으로 전개됨
        // s: 해당 자릿수에서 시작되는 순서값
        // e: 해당 자릿수에서 끝나는 순서값
        long l = 0, m = 0, s = 0, e = 0;
        do
        {
            l++;
            m = (m == 0) ? 1 : m * 10;
            s = e;
            e += 9 * m * l;
        } while(k > e);

        // k번째가 포함된 숫자
        int number = m + (k - s) / l;
        // number에서 k번째 해당하는 숫자는 몇 번째인가
        int index = (k - s) % l;
        if(index == 0) { number -= 1; index = l; }

        // number에서 index 번째 숫자를 찾는다
        int res = 0;
        do
        {
            res = number / m;
            number -= res * m;
            m /= 10;
        } while(--index);

        cout << res;
    }
}