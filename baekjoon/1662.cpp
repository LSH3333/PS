#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Data {
    char c;
    int num;
    bool isNum;
};

int main() {
    string str; cin >> str;

    // char, true 시 계산 완료
    stack<Data> st;
    for(const auto &c : str) {
        if(c == ')') {
            int cnt = 0;

            while (!st.empty() && st.top().c != '(') {
                if(st.top().isNum) {
                    cnt += st.top().num;
                }
                else {
                    cnt++;
                }
                st.pop();
            }

            st.pop(); // '('

            int val = st.top().c - '0';
            cnt = cnt * val;
            st.pop();

            st.push({NULL, cnt, true});
        }
        else {
            st.push({c, 0, false});
        }
    }

    int answer = 0;
    while (!st.empty()) {
        if(st.top().isNum) answer += st.top().num;
        else answer++;
        st.pop();
    }

    cout << answer;
}