#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string str; cin >> str;
    int sum;
    str[0] == 'd' ? sum = 10 : sum = 26;

    for(int i = 1; i < str.size(); i++)
    {
        // 이전과 같은 문자
        if(str[i] == str[i-1])
        {
            if(str[i] == 'd') sum *= 9;
            else sum *= 25;
        }
        else
        {
            if(str[i] == 'd') sum *= 10;
            else sum *= 26;
        }
    }

    cout << sum;
}