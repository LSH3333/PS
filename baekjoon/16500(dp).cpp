#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S;
bool d[101];

bool IsItPossible(int i, const string &a) {
    for(int j = 0; j < a.size(); j++) {
        if(a[j] != S[i+j]) return false;
    }
    return true;
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

    for(int i = 0; i < S.size(); i++) {
        if(i != 0 && !d[i]) continue;

        for(const auto &a : A) {
            if (IsItPossible(i, a)) {
                d[i+a.size()] = true;
            }
        }
    }

    cout << d[S.size()];
}