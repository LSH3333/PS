#include <iostream>
using namespace std;
#include <string>

int main() {
    string s;
    getline(cin, s);

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            int res = s[i] + 13;
            if(res > 'z') s[i] = 'a' + res - 'z'-1;
            else s[i] = res;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            int res = s[i] + 13;
            if(res > 'Z') s[i] = 'A' + res - 'Z'-1;
            else s[i] = res;
        }

    }

    for(auto x : s) cout << x;

}