#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int zero = 0, one = 0;


    for(int i = 0; i < s.size(); i++)
    {
        // change to 1
        if(s[i] == '0' && s[i-1] != '0')
        {
            zero++;
        }
        else if(s[i] == '1' && s[i-1] != '1')
        {
            one++;
        }
    }

    cout << min(zero, one);
}