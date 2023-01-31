#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N;

bool IsItGood(const string &s) {
    for(int len = 2; len <= s.size()/2; len++) {

        for(int i = 0; i < s.size(); i++) {
            if(i+len+len > s.size()) break;
            string s1 = s.substr(i, len);
            string s2 = s.substr(i + len, len);
            if(s1 == s2) return false;
        }
    }
    return true;
}

void dfs(string &s) {
    if(!IsItGood(s)) {
        return;
    }
    if(s.size() == N) {
        cout << s;
        exit(0);
    }


    for(int i = 1; i <= 3; i++) {
        char c = char(i + '0');
        if(s.empty() || s.back() != c) {
            s.push_back(c);
            dfs(s);
            s.pop_back();
        }
    }
}

int main() {
    cin >> N;
    string s;
    dfs(s);
}