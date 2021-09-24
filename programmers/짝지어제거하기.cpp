#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(st.empty() || s[i] != st.top())
        {
            st.push(s[i]);
        }
        else if(s[i] == st.top())
        {
            st.pop();
        }
    }

    return st.empty();
}
