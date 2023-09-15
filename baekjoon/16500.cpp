#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool answer;
string S;
unordered_map<string, bool> mp;

void dfs(const vector<string> &A, string &res) {
    if(res == S) {
        answer = true;
        return;
    }

    for(const auto &a : A) {
        string newStr = res + a;
        if(S.find(newStr) != string::npos && !mp[newStr]) {
            mp[newStr] = true;
            dfs(A, newStr);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> A;
    cin >> S;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string a; cin >> a;
        A.push_back(a);
    }

    string res;
    dfs(A, res);

    cout << answer;
}