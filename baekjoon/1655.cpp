#include <iostream>
#include <queue>
using namespace std;

int N;
int n;

/**
 * left pq와 right pq의 크기를 항상 같게 유지 
 * 홀수 번째 숫자를 삽입해서 총 숫자의 갯수가 홀수개가 될때는 left pq가 하나 더 많아지도록 유지 
 */

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<>> right; // min heap
    cin >> N;
    int n1, n2;

    if(N == 1) {
        cin >> n1; cout << n1;
        return 0;
    }

    // 1st, 2nd
    cin >> n1 >> n2;
    left.push(min(n1, n2));
    right.push(max(n1, n2));
    cout << n1 << '\n';
    cout << min(n1,n2) << '\n';

    if(N == 2) {
        return 0;
    }

    for (int i = 3; i <= N; i++) {
        cin >> n;

        // 현재 짝수번째 경우
        if(i % 2 == 0) {
            if(n < left.top())  {
                if(left.size() > right.size()) {
                    right.push(left.top());
                    left.pop();
                }
                left.push(n);
            }
            else if(right.top() < n) {
                if(left.size() < right.size()) {
                    left.push(right.top());
                    right.pop();
                }
                right.push(n);
            }
            else { // n >= left.top() && n <= right.top()
                if(left.size() > right.size()) right.push(n);
                else left.push(n);
            }
        }

        // 현재 홀수번째 경우
        else {
            if(right.top() <= n) {
                left.push(right.top());
                right.pop();
                right.push(n);
            }
            else {
                left.push(n);
            }
        }

        cout << left.top() << '\n';
    }


}