#include <iostream>
using namespace std;

// 양 한마리가 먹는 사료 a,
// 염소 한마리가 먹는 사료 b,
// 전체마리수 n,
// 전체소비 사료양 w
int a, b, n, w;

int s_num, g_num;
// 답이 두개 이상이면 -1을 출력해야함
int cnt = 0;

int main()
{
    cin >> a >> b >> n >> w;

    for(int i = 1; i < n; i++)
    {
        int sheep = i;
        int goat = n-i;
        int res = (a * sheep) + (b * goat);

        if(res == w)
        {
            cnt++;
            s_num = sheep;
            g_num = goat;
        }
    }

    // 해가 하나인 경우
    if(cnt == 1)
        cout << s_num << ' ' << g_num << '\n';
    // 해가 두개 이상이거나 없을 경우
    else
        cout << -1 << '\n';


}