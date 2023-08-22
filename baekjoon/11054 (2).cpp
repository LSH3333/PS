#include <iostream>
#include <vector>
using namespace std;

int N;
int a[1001];
int answer;

int Find(int idx, int num) {
    int ret = 0;

    vector<int> d(N, 1);
    for(int i = N-1; i >= idx; i--) {
        if(a[i] >= num) continue;
        for(int j = N-1; j > i; j--) {
            if(a[j] < a[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        ret = max(ret, d[i]);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> d(N, 1);
    int leftMax = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }

        leftMax = max(leftMax, d[i]);
        int ret = Find(i + 1, a[i]);
        answer = max(answer, leftMax + ret);
    }

    cout << answer;
}