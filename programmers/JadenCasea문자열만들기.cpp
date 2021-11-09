#include <iostream>
#include <vector>
using namespace std;

string solution(string s)
{

    bool afterBlank = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            afterBlank = true;
            continue;
        }

        if(afterBlank)
        {
            s[i] = toupper(s[i]);
            afterBlank = false;
        }
        else
        {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}
