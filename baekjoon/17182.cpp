#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, answer=100000000;
int d[11][11];

void FloydWarshall() {
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    vector<int> v;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> d[i][j];
        }
        if(i != K) {
            v.push_back(i);
        }
    }

    FloydWarshall();

    do {
        int total = 0, cur = K;
        for(auto x : v) {
            total += d[cur][x];
            cur = x;
        }

        answer = min(answer, total);
    } while (next_permutation(v.begin(), v.end()));

    cout << answer;
}