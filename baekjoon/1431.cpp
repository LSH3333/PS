#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int GetSum(const string &str) {
    int sum = 0;
    for(auto c : str) {
        if (c >= '0' && c <= '9') {
            sum += int(c - '0');
        }
    }
    return sum;
}

bool cmp(const string &a, const string &b) {
    if(a.size() == b.size()) {
        int aSum = GetSum(a), bSum = GetSum(b);
        if (aSum == bSum) {
            return a < b;
        }
        return GetSum(a) < GetSum(b);
    }
    return a.size() < b.size();
}

int main() {
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for(auto x : v) {
        cout << x << '\n';
    }
}