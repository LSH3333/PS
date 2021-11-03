#include <iostream>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        string n,m;
        int ans = 0;
        cin >> n >> m;

        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] == m[i]) continue;

            // 2번 연산할수 있으면 2번연산 진행
            bool trigger = false;
            char target = m[i];
            for(int j = i; j < n.size(); j++)
            {
                if(m[j] != target && n[j] == target)
                {
                    // swap
                    char temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;
                    ans++;
                    trigger = true;
                    break;
                }
            }

            // 2번연산 못했으면 1번연산 진행
            if(!trigger)
            {
                // 사실 현재 자리 기준 지나온 자리들은 이미 n과m이 동일한게 보장되므로
                // 2번연산은 실제로 숫자를 바꿔줄 필요는 없고 연산횟수만 증가시켜도 된다
//            if(m[i] == '1')
//                m[i] = '0';
//            else
//                m[i] = '1';
                ans++;
            }
        }

        cout << ans << '\n';
    }


}