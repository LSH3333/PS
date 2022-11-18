#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        unordered_map<int, int> map;
        cin >> N;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                maxHeap.push(num);
                minHeap.push(num);
                map[num]++;
                cnt++;
            }
            else if(op == 'D') {
                if(cnt == 0) {
                    continue;
                }
                if(num == 1) {
                    while(true) {
                        if(map[maxHeap.top()] == 0) {
                            maxHeap.pop();
                        }
                        else if(map[maxHeap.top()] > 0) {
                            map[maxHeap.top()]--;
                            break;
                        }
                    }
                }
                else if(num == -1) {
                    while(true) {
                        if(map[minHeap.top()] == 0) {
                            minHeap.pop();
                        }
                        else if(map[minHeap.top()] > 0) {
                            map[minHeap.top()]--;
                            break;
                        }
                    }
                }
                cnt--;
            }
        }

        if(cnt == 0) {
            cout << "EMPTY\n";
        }
        else {
            // max
            while(true) {
                int top = maxHeap.top();
                maxHeap.pop();
                if(map[top] > 0) {
                    cout << top << ' ';
                    break;
                }
            }
            // min
            while(true) {
                int top = minHeap.top();
                minHeap.pop();
                if(map[top] > 0) {
                    cout << top << '\n';
                    break;
                }
            }
        }
    }

}