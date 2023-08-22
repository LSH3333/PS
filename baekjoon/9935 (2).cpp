#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str, bomb;
    cin >> str >> bomb;

    stack<pair<char,int>> st;
    int bombIdx = 0;

    for(const auto &c : str) {
        if (st.empty()) {
            if(c == bomb.front()) {
                st.push({c, 1});
            } else {
                st.push({c, 0});
            }
        }

        else {
            // ?? ???? ???? ??
            if(bomb[st.top().second+1-1] == c) {
                st.push({c, st.top().second + 1});
            }
            else {
                if(c == bomb.front()) {
                    st.push({c, 1});
                } else {
                    st.push({c, 0});
                }
            }
        }
        // ?? ??? ??
        if (st.top().second == (int) bomb.size()) {
            // ???? ?? ??? ??
            for(int i = 0; i < bomb.size(); i++) {
                st.pop();
            }
        }
    }

    if (st.empty()) {
        cout << "FRULA";
    } else {
        string answer;
        while (!st.empty()) {
            answer.push_back(st.top().first);
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer;
    }

}