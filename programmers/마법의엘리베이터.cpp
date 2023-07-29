#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100000000

int d[MAX+1];

void Check(int n, int c, queue<int> &q) {
    while(n + c <= MAX && n + c >= 0) {
        if(d[n+c] > d[n] + 1) {
            d[n+c] = d[n] + 1;
            q.push(n + c);
        }
        c *= 10;
    }
}

int solution(int storey) {
    int answer = 0;
    fill(d, d+MAX+1, MAX);

    d[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if(n == storey) {
            answer = d[n];
            break;
        }

        if (n < storey) {
            Check(n, 1, q);
        }
        else {
            Check(n, -1, q);
        }
    }

    return answer;
}

int main() {
    cout << solution(2554);
}