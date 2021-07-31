#include <iostream>
using namespace std;

// int형의 숫자를 string으로 변환해 0의 갯수를 샌다
int CountZero(int num)
{
    int cnt = 0;
    string str = to_string(num);

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '0') cnt++;
    }

    return cnt;
}

int main()
{
    int testcase;
    cin >> testcase;

    for(int tc = 0; tc < testcase; tc++)
    {
        int n,m;
        int ans = 0;
        cin >> n >> m;

        for(int i = n; i <= m; i++)
        {
            ans += CountZero(i);
        }
        cout << ans << '\n';
    }
}