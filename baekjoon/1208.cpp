#include <iostream>
#include <map>
using namespace std;

int N, S;
long long answer;
int a[41];
map<int,int> m;

void dfsLeft(int i, int sum) {
    if(i == N/2) {
        m[sum]++;
        return;
    }

    dfsLeft(i+1, sum);
    dfsLeft(i + 1, sum + a[i]);
}

void dfsRight(int i, int sum) {
    if(i == N) {
        answer += m[S-sum];
        return;
    }

    dfsRight(i+1,sum);
    dfsRight(i + 1, sum + a[i]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for(int i = 0 ; i < N; i++) {
        cin >> a[i];
    }

    dfsLeft(0, 0);
    dfsRight(N/2, 0);

    if(S == 0) {
        cout << answer-1;
    } else {
        cout << answer;
    }
}