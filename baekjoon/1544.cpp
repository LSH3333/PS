#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> v;

bool CheckSame(string newStr, const string &str) {
    if(newStr.size() != str.size()) return false;
    for(int i = 0; i < str.size(); i++) {
        if(newStr == str) return true;
        newStr.push_back(newStr.front());
        newStr = newStr.substr(1);
    }
    return false;
}

void Check(const string &newStr) {
    for(const auto &str : v) {
        if(CheckSame(newStr, str)) {
            return;
        }
    }

    v.push_back(newStr);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string newStr; cin >> newStr;
        Check(newStr);
    }

    cout << v.size();
}