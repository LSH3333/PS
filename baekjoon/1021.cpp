#include <iostream>
#include <deque>
using namespace std;

int N, M, answer;
int a[51];

bool FindWay(deque<int> &dq, int n) {
    int fromLeft = 0, fromRight = 0;
    for(fromLeft = 0; fromLeft < dq.size(); fromLeft++) {
        if(dq[fromLeft] == n) {
            break;
        }
    }

    for(fromRight = (int)dq.size()-1; fromRight >= 0; fromRight--) {
        if(dq[fromRight] == n) {
            fromRight = (int)dq.size() - fromRight - 1;
            break;
        }
    }

    return fromLeft <= fromRight;
}

int MoveLeft(deque<int> &dq, int n) {
    int cnt = 0;
    while(!dq.empty() && dq.front() != n) {
        int f = dq.front();
        dq.pop_front();
        dq.push_back(f);
        cnt++;
    }
    return cnt;
}

int MoveRight(deque<int> &dq, int n) {
    int cnt = 0;
    while(!dq.empty() && dq.back() != n) {
        int b = dq.back();
        dq.pop_back();
        dq.push_front(b);
        cnt++;
    }
    return cnt;
}

int main() {
    deque<int> dq;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for(int i = 0; i < M; i++) {
        int n = a[i];

        bool fromLeft = FindWay(dq, n);
        if(fromLeft) {
            answer += MoveLeft(dq, n);
            dq.pop_front();
        } else {
            answer += MoveRight(dq, n) + 1;
            dq.pop_back();
        }
    }

    cout << answer;
}