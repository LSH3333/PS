#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000000
#define INF 10000000
int d[MAX+1];

int main() {
    int X;
    cin >> X;

    fill(d, d+MAX+1, INF);
    queue<int> q;

    d[X] = 0;
    q.push(X);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if(x % 3 == 0 && d[x/3] > d[x] + 1) {
            d[x/3] = d[x] + 1;
            q.push(x / 3);
        }
        if(x % 2 == 0 && d[x/2] > d[x] + 1) {
            d[x/2] = d[x] + 1;
            q.push(x / 2);
        }
        if(x-1 >= 0 && d[x-1] > d[x] + 1) {
            d[x-1] = d[x] + 1;
            q.push(x - 1);
        }
    }

    cout << d[1];
}