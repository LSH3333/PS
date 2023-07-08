#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);

    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        v[i] = str;
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(),v.end()), v.end());

    for(auto x : v) {
        cout << x << '\n';
    }
}
