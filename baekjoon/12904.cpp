#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S,T;

int main()
{
    cin >> S >> T;

    while(T.size() >= 1)
    {
        // 맨뒤에 A가 있으면 A를 제거 (1번연산)
        if(T.back() == 'A')
        {
            T = T.substr(0, T.size()-1);
        }
        else // 1번연산 불가능하면 2번연산 : 맨뒤 제거하고 뒤집는다
        {
            T = T.substr(0, T.size()-1);
            reverse(T.begin(), T.end());
        }

        // S가 만들어지면 1출력후 종료
        if(T == S)
        {
            cout << 1;
            return 0;
        }
    }
    // S가 안만들어짐
    cout << 0;
}
