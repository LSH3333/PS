#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
int N;
int timer[] = {60, 10, -10, 1, -1};
int d[70];

struct Data {
    int n;
    int a,b,c,d,e;
};

Data bfs() {
    queue<Data> q;
    q.push({0, 0, 0, 0, 0, 0});
    d[0] = 0;

    while (!q.empty()) {
        Data data = q.front();
        q.pop();

        if(data.n == N) {
            return data;
        }

        for(int i = 4; i >= 0; i--) {
            int next = data.n + timer[i];
            if(next < 0) next = 0;

            if (next <= 60 && d[next] > d[data.n] + 1) {
                d[next] = d[data.n] + 1;

                if(i == 0) q.push({next, data.a + 1, data.b, data.c, data.d, data.e});
                else if(i == 1) q.push({next, data.a, data.b+1, data.c, data.d, data.e});
                else if(i == 2) q.push({next, data.a, data.b, data.c+1, data.d, data.e});
                else if(i == 3) q.push({next, data.a, data.b, data.c, data.d+1, data.e});
                else q.push({next, data.a, data.b, data.c, data.d, data.e+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < 70; i++) d[i] = INF;
        int btn60 = N / 60;
        N = N % 60;

        Data data = bfs();
        cout << data.a+btn60 << ' ' << data.b << ' ' << data.c << ' ' << data.d << ' ' << data.e <<'\n';
    }

}