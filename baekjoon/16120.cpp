#include <iostream>
#include <stack>
using namespace std;

int main() {
    string ip; cin >> ip;

    stack<char> st;

    for(const auto &c : ip) {
        st.push(c);

        if((int)st.size() >= 4) {
            string str;
            for(int i = 0; i < 4; i++) {
                str.push_back(st.top());
                st.pop();
            }

            if(str == "PAPP") {
                st.push('P');
            }
            else {
                for(int i = 3; i >= 0; i--) st.push(str[i]);
            }
        }
    }


    if(st.size() == 1 && st.top() == 'P') cout << "PPAP";
    else cout << "NP";
}