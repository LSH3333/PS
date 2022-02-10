#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// n이 몇자리인지
int GetPos(int n)
{
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
    // 자릿수
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int nPos = GetPos(n);
    if(k > nPos) { cout << -1; return 0;}
    int cnt = 1;
    int num1 = 9, num2 = 1;
    while(true)
    {
        if(num1 * num2 > k) break;
        num1 *= 10;
        num2++;
        cnt++;
    }
    // pos의 자리
//    cout << cnt << endl;
    int pos = pow(10, cnt-1);
//    cout << "pos: " << pos << endl;

    int num = pos;
    while(true)
    {
        if(pos > k) break;
        num++;
        pos += cnt;
    }

    num--; pos -= cnt;
    string num_s = to_string(num);
    char answer = num_s[k-pos];
    cout << answer;

}