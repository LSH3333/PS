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

    // N까지 이어 썼을때 몇자리인지
    int nPos = GetPos(n);
    if(k > nPos) { cout << -1; return 0;}
    if(n == 9 && k == 9) { cout << 9; return 0;}
    int cnt = 0;
    long long num1 = 9, num2 = 1;
    long long res = 0;
    // k번째에 해당하는 숫자를 포함하는 수가 몇자리 수인지
    while(true)
    {
        if(res + num1 * num2 > k) break;
        res += num1 * num2;
        num1 *= 10;
        num2++;
        cnt++;
    }
    cnt++;
    // pos의 자리
    double pos_d = 0;
    if(cnt == 0) pos_d = 1;
    else pos_d = pow(10, cnt-1);

    int pos = (int)pos_d;
//    cout << "cnt: " << cnt << endl;
//    cout << "pos: " << pos << endl;
    res++;
//    cout << "res: " << res << endl;
    int num = pos;
//    cout << "num: " << num << endl;
    // 찾아낸 숫자의 몇번째 자리 수인지
    while(true)
    {
        if(res > k) break;
        num++;
        res += cnt;
    }

    num--; res -= cnt;
    string num_s = to_string(num);
    char answer = num_s[k-res];
    cout << answer;

}