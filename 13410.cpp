#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 단의수, 항의수
int n,k;
int ans = 0;

int main()
{
    cin >> n >> k;

    for(int i = 1; i <= k; i++)
    {
        // 계산 결과
        int res = n * i;
        // 계산 결과를 string 으로 변환
        string str = to_string(res);
        // 계산 결과를 뒤집는다
        reverse(str.begin(), str.end());
        // 최댓값 갱신
        ans = max(ans, stoi(str));
    }

    cout << ans;

}

