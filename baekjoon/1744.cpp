#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> v(N);
    vector<int> answer;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> tmp;
    // 2 이상
    while(!v.empty() && v.back() > 1) {
        tmp.push_back(v.back());
        v.pop_back();
    }

    for(int i = 0; i < tmp.size(); i += 2) {
        if(i+1 >= tmp.size()) {
            answer.push_back(tmp[i]);
        }
        else {
            answer.push_back(tmp[i] * tmp[i + 1]);
        }
    }
    tmp.clear();

    // 1
    while(!v.empty() && v.back() == 1) {
        answer.push_back(1);
        v.pop_back();
    }

    // 0 이하
    for(int i = 0; i < v.size(); i += 2) {
        if(i+1 >= v.size()) {
            answer.push_back(v[i]);
        }
        else {
            answer.push_back(v[i] * v[i + 1]);
        }
    }
    
    int ans = 0;
    for(auto x : answer) {
        ans += x;
    }
    cout << ans;
}