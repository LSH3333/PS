#include <iostream>
#include <queue>
using namespace std;

int N, W, L;
int answer;

void Print(const vector<int> &bridge) {
    for(auto x : bridge) {
        cout << x << ' ';
    } cout << endl;
}

void Move(vector<int> &bridge, int &total) {
    // ?? ??
    total -= bridge.back();
    for(int i = (int)bridge.size()-1; i > 0; i--) {
        bridge[i] = bridge[i-1];
    }
    bridge.front() = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W >> L;
    queue<int> q;
    vector<int> bridge(W);
    for(int i = 0; i < N; i++) {
        int w; cin >> w;
        q.push(w);
    }

    int total = 0;
    while (!q.empty()) {
        Move(bridge, total);
        answer++;

        if(total + q.front() <= L) {
            bridge[0] = q.front();
            total += q.front();
            q.pop();
        }
    }
    while(total > 0) {
        Move(bridge, total);
        answer++;
    }

    cout << answer;
}