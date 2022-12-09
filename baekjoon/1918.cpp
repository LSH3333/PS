#include <iostream>
#include <stack>
using namespace std;

/**
 * +, - : 스택에 있는 연산자들은 우선순위가 나보다 크거나 같기 때문에, '(' 전까지 모두 빼서 res에 붙이고, 나는 스택에 푸쉬
 *  /, * : 나는 스택에 있는 연산자들보다 우선순위가 크거나 같기 때문에, 스택에 있는 *, / 들은 빼서 res에 붙이고 나는 스택에 푸쉬
 */

int main() {
    string exp; cin >> exp;

    stack<char> st;
    string res;
    for(const auto &x : exp) {
        if (x >= 'A' && x <= 'Z') {
            res.push_back(x);
        }
        else if (x == '+' || x == '-') {
            while(!st.empty() && st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
        else if (x == '*' || x == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                res.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
        else if (x == '(') {
            st.push('(');
        }
        else  { // ')'
            while (!st.empty() && st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
    }

    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    cout << res;
}