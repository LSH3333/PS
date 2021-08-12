#include <iostream>
#include <string>
using namespace std;

string s;
string ans = "";

int main()
{
    cin >> s;
    s.push_back('Y'); // 문자열의 마지막 표시

    int Xcnt = 0;
    // 연속된 X의 갯수를 카운트해서 홀수면 -1 출력 후 종료
    // 짝수면 적절한 폴리오미노 삽입
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'X')
            Xcnt++;

        if(s[i] == '.' || s[i] == 'Y')
        {
            // X갯수 짝수일때
            if(Xcnt % 2 == 0)
            {
                while(Xcnt > 0)
                {
                    if(Xcnt >= 4)
                    {
                        for(int j = 0; j < 4; j++)
                            ans.push_back('A');
                        Xcnt -= 4;
                    }
                    else if(Xcnt == 2)
                    {
                        for(int j = 0; j < 2; j++)
                            ans.push_back('B');
                        Xcnt -= 2;
                    }
                }
            }
            else
            {
                cout << -1;
                return 0;
            }
            if(s[i] == '.')
                ans.push_back('.');
        }

    }


    cout << ans;
}