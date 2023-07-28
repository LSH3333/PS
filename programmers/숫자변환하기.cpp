#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 1000000
#define INF 100000000
int d[MAX+1];

int solution(int x, int y, int n) {
    int answer = -1;
    fill(d, d+MAX+1, INF);
    queue<int> q;

    q.push(y);
    d[y] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == x) {
            answer = d[cur];
            break;
        }

        if(cur % 2 == 0 && d[cur/2] > d[cur] + 1) {
            d[cur/2] = d[cur] + 1;
            q.push(cur / 2);
        }
        if(cur % 3 == 0 && d[cur/3] > d[cur] + 1) {
            d[cur/3] = d[cur] + 1;
            q.push(cur / 3);
        }
        if(cur-n >= x && d[cur-n] > d[cur] + 1) {
            d[cur-n] = d[cur] + 1;
            q.push(cur - n);
        }
    }

    return answer;
}

int main() {
    cout << solution(10, 40, 5);
}