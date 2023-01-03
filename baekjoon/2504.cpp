#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool IsItNumber(const string &s) {
    if(s == "(" || s == ")" || s == "[" || s == "]") return false;
    return true;
}

bool StackPush(const string &s, stack<string> &st) {
    if(st.empty() || s == "(" || s == "[") {
        st.push(s); return true;
    }


    if (st.top() == "(" && s == ")") {
        st.pop();
        st.push("2");
    }
    else if (st.top() == "[" && s == "]") {
        st.pop();
        st.push("3");
    }
    else { // top 이 숫자인 경우
        string target = s == ")" ? "(" : "[";
        int sum = 0;
        bool found = false;
        while(!st.empty()) {
            if(st.top() == target) {
                found = true;
                break;
            }
            if(!IsItNumber(st.top())) return false;
            sum += stoi(st.top());
            st.pop();
        }
        if(!found) return false;
        st.pop();
        if(target == "[") st.push(to_string(sum * 3));
        else st.push(to_string(sum * 2));
    }
    return true;
}

int main() {
    string ip; cin >> ip;
    stack<string> st;

    for(auto x : ip) {
        string s; s.push_back(x);
        bool res = StackPush(s, st);
        if(!res) {
            cout << 0; exit(0);
        }
    }

    int answer = 0;
    while(!st.empty()) {
        if(!IsItNumber(st.top())) { cout << 0; exit(0); }
        answer += stoi(st.top());
        st.pop();
    }
    cout << answer;
}