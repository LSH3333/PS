#include <iostream>
#include <stack>
using namespace std;

void Check(string &str, const string &bombStr)
{
    string ret;
    stack<int> st;

    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if(st.empty())
        {
            if(c == bombStr.front()) st.push(1);
            else st.push(0);
        }
        else
        {
            if(c == bombStr[st.top()])
            {
                st.push(st.top()+1);
            }
            else
            {
                if(c == bombStr.front()) st.push(1);
                else st.push(0);
            }
        }

        ret.push_back(c);

        if(st.top() == bombStr.size())
        {
            int top = st.top();
            while(top-- > 0)
            {
                st.pop();
                ret.pop_back();
            }
        }
    }

    if(ret.empty()) cout << "FRULA";
    else cout << ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    string bombStr; cin >> bombStr;

    Check(str, bombStr);

}