#include <iostream>
#include <string>

using namespace std;

string s;

// 팰린드롬인지 판별
bool IsItPalindrome(string str)
{
    int mid = str.size() / 2;

    for(int i = 0; i < mid; i++)
    {
        if(str[i] != str[str.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    cin >> s;

    // 문자열 s를 앞에서부터 잘라서 팰린드롬을 찾는다
    for(int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(i, s.size()-i);

        if(IsItPalindrome(temp))
        {
            cout <<  s.size() + i;
            return 0;
        }
    }
}