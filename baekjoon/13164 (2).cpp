#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    vector<int> v(N), dist;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++) {
        dist.push_back(v[i] - v[i - 1]);
    }

    sort(dist.begin(), dist.end(), greater<>());


    int answer = 0;
    for(int i = K-1; i < dist.size(); i++) {
        answer += dist[i];
    }

    cout << answer;
}