#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int N,K;
int arr[MAX];
int mark[MAX];
int idx = 1;
int dc[3] = {-1, 1, 2}; /* 좌측1칸, 우측1칸, 두배(곱하기) */

void bfs() {
    queue<int> q;
    q.push(N);
    mark[N] = idx;

    while(!q.empty()) {
        int c = q.front();
        q.pop();
        if(mark[c] > idx) idx++;

        for(int i = 0; i < 3; i++) {
            int nc;
            if(i == 2) { /* 순간이동, 곱하기 */
                nc = c * dc[i];
            }
            else { /* 좌측, 우측 1칸 이동 */
                nc = c + dc[i];
            }

            if(nc < 0 || nc > MAX) continue;
            if(mark[nc] == 0) {
                mark[nc] = idx + 1;
                q.push(nc);
            }

        }
    }
}

int main() {
    cin >> N >> K;
    bfs();

    cout << mark[K]-1;

}