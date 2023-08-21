#include <iostream>
#include <stack>
#include <string>
using namespace std;

int GetPriority(char c) {
    if(c == '+' || c == '-') return 0;
    else return 1;
}

int main() {
    string exp; cin >> exp;
    stack<char> st;
    string res;
    for (const auto &c: exp) {
        // ????
        if (c >= 'A' && c <= 'Z') {
            res.push_back(c);
        }
        else if(c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // '('
            }
        }
            // ???
        else {
            // ?? ???? ????? ???? ?? ???? ?? res ? ?? (????)
            while (!st.empty() && GetPriority(st.top()) >= GetPriority(c) && st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    cout << res;
}