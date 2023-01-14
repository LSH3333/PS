#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int parent[3010];
int arr[3010][3];
int unionCnt;

int FindParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = FindParent(parent[node]);
}

void Union(int node1, int node2) {
    node1 = FindParent(node1);
    node2 = FindParent(node2);
    parent[max(node1, node2)] = min(node1, node2);
}

void Init() {
    unionCnt = 0;
    for(int i = 0; i < N; i++) {
        parent[i] = i;
        arr[i][0] = 0; arr[i][1] = 0; arr[i][2] = 0;
    }
}



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        cin >> N;
        Init();
        for(int i = 0; i < N; i++) {
            int x, y, r; cin >> x >> y >> r;
            arr[i][0] = x;
            arr[i][1] = y;
            arr[i][2] = r;
        }

        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(FindParent(i) == FindParent(j)) continue;
                int x1 = arr[i][0], y1 = arr[i][1], r1 = arr[i][2];
                int x2 = arr[j][0], y2 = arr[j][1], r2 = arr[j][2];
                double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                if(r1 + r2 >= distance) {
                    Union(i, j);
                    unionCnt++;
                }
            }
        }
        cout << N-unionCnt << '\n';
    }

}