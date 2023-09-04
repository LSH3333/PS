#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer;

int main() {
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());

    // pick 2
    answer = v[0] * v[1];
    answer = max(answer, v[v.size() - 1] * v[v.size() - 2]);

    // pick 3
    answer = max(answer, v[0] * v[1] * v[2]);
    answer = max(answer, v[0] * v[v.size() - 1] * v[v.size() - 2]);

    cout << answer;
}