#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    // max heap
    priority_queue<int> pq;

    int i = 0;
    for(i = 0; i < enemy.size(); i++) {
        int x = enemy[i];
        // ??? ??? ?
        if(n - x >= 0) {
            pq.push(x);
            n -= x;
        }
            // ??? ?? ?
        else {
            // ??? ? ?
            if(k == 0) {
                break;
            }
            pq.push(x);
            n = n - x + pq.top();
            k--;
            pq.pop();
        }
    }

    answer = i;
    return answer;
}

int main() {
    int n = 2;
    int k = 1;
    vector<int> enemy = {10,10,10,10};
    cout << solution(n, k, enemy);
}