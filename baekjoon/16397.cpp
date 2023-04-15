#include <iostream>
#include <queue>
using namespace std;

#define MAX 99999

int N, T, G;
int mark[MAX+5];

int GetB(int n) {
    if(n == 0) return n;
    n *= 2;
    if(n > MAX) return -1;
    int len = to_string(n).size();
    int sub = 1;
    for(int i = 0; i < len-1; i++) sub *= 10;
    n -= sub;
    if(n > MAX) return -1;
    return n;
}

int bfs() {
    if(N == G) return 0;
    queue<pair<int,int>> q;
    q.push({N, 0});

    while (!q.empty()) {
        int n = q.front().first;
        int cnt = q.front().second;
        if(cnt >= T) return -1;
        q.pop();

        int A = n + 1;
        if(A == G) return cnt+1;
        if(mark[A] > cnt + 1) {
            mark[A] = cnt + 1;
            q.push({A, cnt + 1});
        }

        int B = GetB(n);
        if(B == G) return cnt+1;
        if(B != -1 && mark[B] > cnt + 1) {
            mark[B] = cnt + 1;
            q.push({B, cnt + 1});
        }
    }

    return -1;
}

int main() {
    cin >> N >> T >> G;

    for(int i = 0; i <= MAX; i++) mark[i] = MAX;
    int answer = bfs();
    if(answer == -1) {
        cout << "ANG";
    }
    else {
        cout << answer;
    }


}