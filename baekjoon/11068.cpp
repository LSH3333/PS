#include <iostream>
using namespace std;

// num을 n진법으로 표현
string MakeNotation(int n, int num)
{
    string temp = "";
    while(num > 0)
    {
        int left = num % n;
        num /= n;
        temp += left+'0';
    }
    return temp;
}

// num이 회문인지 판별
bool IsItPalindrome(string num)
{
    int midIdx = num.size()/2;

    for(int i = 0; i < midIdx; i++)
    {
        if(num[i] != num[num.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int num;
        cin >> num;

        bool flag = false;
        for(int i = 2; i <= 64; i++)
        {
            // 회문인 경우가 하나라도 있으면 flag=true
            if(IsItPalindrome(MakeNotation(i, num)))
            {
                flag = true;
                break;
            }
        }

        if(flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

}