#include <iostream>
#include <stack>
using namespace std;

bool sol(const string& ps) {
    stack<char> st;

    for(auto x : ps) {
        if(st.empty()) {
            st.push(x);
        }
        else {
            if (x == '(') {
                st.push(x);
            }
            else {
                if(st.top() == '(') st.pop();
            }
        }
    }

    if(st.empty()) return true;
    else return false;
}

int main() {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        string ps; cin >> ps;
        bool res = sol(ps);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }

}