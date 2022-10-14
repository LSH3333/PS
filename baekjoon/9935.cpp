#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    string str; cin >> str;
    string bombStr; cin >> bombStr;

    bool found = false;
    int count = 0;
    stack<char> st;

    for(int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if(c == bombStr[count])
        {
            count++;
        }
        else
        {
            if(c == bombStr[0]) count = 1;
            else count = 0;
        }
        st.push(c);

        if(count == bombStr.size())
        {
            for(int j = 0; j < count; j++) st.pop();
            count = 0;
            found = true;
        }
    }

    vector<char> ans(st.size());
    int idx = (int)st.size()-1;
    while(!st.empty())
    {
        ans[idx--] = st.top();
        st.pop();
    }
    for(auto x : ans) cout << x;



}