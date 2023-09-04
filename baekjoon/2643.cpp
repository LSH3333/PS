#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
int d[101];

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() {
    cin >> N;
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++) {
        int l1, l2;
        cin >> l1 >> l2;
        v.push_back({max(l1, l2), min(l1, l2)});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++) {
        int maxVal = 1;
        for(int j = i-1; j >= 0; j--) {
            if (v[j].first >= v[i].first && v[j].second >= v[i].second) {
                maxVal = max(maxVal, d[j]+1);
            }
        }
        d[i] = maxVal;
        answer = max(answer, d[i]);
    }

    cout << answer;
}