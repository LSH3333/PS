#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string n, m;
    cin >> n >> m;
    // 자리수 맞춰줌
    while(n.size() != m.size())
        n = "0" + n;

    int cnt = 0;
    string _n = n, _m = m; // 원본 저장
    for(int i = n.size()-1; i >= 0; i--)
    {
        if(n[i] == '8' && m[i] == '8')
        {
            // n의 해당자리수 값 증가시켰을때 m보다 커지면 그 자리는 바꿀수없음
            n[i] = '9';
            if(n > m) cnt++;
            else {n = _n; m = _m;}
        }
    }
    cout << cnt;
}