#include <iostream>
#include <string>
#include <set>
using namespace std;

bool Check(const string &str, int len) {
    set<string> st;

    int cnt = 0;
    int l = 0;
    while(l < (int)str.size()) {
        int r = l + len + 1;
        if(r >= str.size()) break;
        string sub;
        sub.push_back(str[l]);
        sub.push_back(str[r]);
        st.insert(sub);
        cnt++;
        l++;
    }

    if(st.size() == cnt) {
        return true;
    }
    else {
        return false;
    }
}

bool CheckAll(const string &str) {
    int N = (int)str.size();
    for(int i = 0; i <= N-2; i++) {
        bool res = Check(str, i);
        if(!res) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        string str; cin >> str;
        if(str == "*") {
            break;
        }

        if(CheckAll(str)) {
            cout << str << " is surprising.\n";
        } else {
            cout << str << " is NOT surprising.\n";
        }
    }



}