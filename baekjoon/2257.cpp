#include <iostream>
#include <stack>
using namespace std;

bool IsChar(char c) {
    if (c == 'H' || c == 'C' || c == 'O') return true;
    else return false;
}

bool IsDigit(char c) {
    if(c >= '2' && c <= '9') return true;
    else return false;
}

string cal(char c) {
    if(c == 'H') return "1";
    else if(c == 'C') return "12";
    else return "16";
}

int main() {
    string str; cin >> str;
    stack<string> st;

    for(auto c : str) {
        if(c == '(') {
            st.push("(");
        }
        else if(IsChar(c)) {
            st.push(cal(c));
        }
        else if(IsDigit(c)) {
            int res = stoi(st.top()) * int(c-'0');
            st.pop();
            st.push(to_string(res));
        }
        else if(c == ')') {
            int res = 0;
            while(!st.empty() && st.top() != "(") {
                res += stoi(st.top());
                st.pop();
            }
            st.pop(); // '('
            st.push(to_string(res));
        }
    }


    int answer = 0;
    while (!st.empty()) {
        answer += stoi(st.top());
        st.pop();
    }
    cout << answer;
}