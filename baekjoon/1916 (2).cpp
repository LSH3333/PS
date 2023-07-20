#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000
#define INF 2000000000

int N, M;
int StartNode, EndNode;
vector<pair<int,long long>> edges[MAX+10];
long long mark[MAX+10];


void bfs() {
    // {distance, node} min heap
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, StartNode});
    mark[StartNode] = 0;

    while(!pq.empty()) {
        int curNode = pq.top().second;
        long long distance = pq.top().first;
        pq.pop();

        if(mark[curNode] < distance) continue;

        for (auto next: edges[curNode]) {
            int nextNode = next.first;
            long long nextDistance = distance + next.second;

            if(mark[nextNode] > nextDistance) {
                mark[nextNode] = nextDistance;
                pq.push({nextDistance, nextNode});
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b; long long c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
    }
    cin >> StartNode >> EndNode;

    fill(mark, mark+MAX+10, INF);

    bfs();

    cout << mark[EndNode];
}