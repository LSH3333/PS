#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v;
int d[110];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    d[0] = 1;
    for(int i = 0; i < N; i++) {
        int maxVal = 0;
        for(int j = 0; j < i; j++) {
            if(v[j].second < v[i].second) {
                maxVal = max(maxVal, d[j]);
            }
        }
        d[i] = maxVal + 1;
    }

    int answer = 0;
    for(int i = 0 ; i < N; i++) {
        answer = max(answer, d[i]);
    }

    cout << N - answer;
}