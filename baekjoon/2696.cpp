#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Push(int n, priority_queue<int> &left, priority_queue<int, vector<int>, greater<>> &right) {
    if(left.size() >= right.size()) {
        if(left.empty()) {
            left.push(n);
        }
        else if(n <= left.top()) {
            right.push(left.top());
            left.pop();
            left.push(n);
        }
        else {
            right.push(n);
        }
    }
    else {
        if(n >= right.top()) {
            left.push(right.top());
            right.pop();
            right.push(n);
        }
        else {
            left.push(n);
        }
    }
}

void Print(vector<int> &answer) {
    cout << answer.size() << '\n';
    int cnt = 0;
    for(auto x : answer) {
        cout << x << ' ';
        if(++cnt >= 10) {
            cout << '\n';
            cnt = 0;
        }
    }
    cout << '\n';
}

int main() {
    int N; cin >> N;
    while(N--) {
        vector<int> answer;
        priority_queue<int> left; // max heap
        priority_queue<int, vector<int>, greater<>> right; // min heap
        int M;
        cin >> M;

        for(int i = 1; i <= M; i++) {
            int n; cin >> n;

            Push(n, left, right);

            if(i % 2 != 0) {
                if(left.size() > right.size()) {
                    answer.push_back(left.top());
                }
                else {
                    answer.push_back(right.top());
                }
            }
        }

        Print(answer);
    }


}