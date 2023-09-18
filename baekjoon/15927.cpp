#include <iostream>
#include <string>
using namespace std;

bool IsItPalindrome(const string &str) {
    int N = (int)str.size();
    int l = 0, r = N-1;
    while(l < r) {
        if(str[l] != str[r]) return false;
        l++; r--;
    }
    return true;
}

bool IsAllSame(const string &str) {
    for(int i = 0; i < str.size()-1; i++) {
        if(str[i] != str[i+1]) return false;
    }
    return true;
}

int main() {
    string str; cin >> str;

    // ??? ??? ??
    if(IsItPalindrome(str)) {
        // ?? ?? ??? ??? ?? ??
        if(IsAllSame(str)) {
            cout << -1;
        }
            // ?? ?? ?? ????
        else {
            cout << str.size() - 1;
        }
    }
    else {
        cout << str.size();
    }
}