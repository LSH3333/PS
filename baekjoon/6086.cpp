#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000
#define MAX 52

int N;
int flow[MAX][MAX];
int capacity[MAX][MAX];

int EdmondsKarp() {
    int start = 'A'-'A', goal = 'Z'-'A';
    int answer = 0;

    while(true) {
        vector<int> parent(MAX, -1);
        queue<int> q;
        parent[start] = start;
        q.push(start);

        // 증가 경로 탐색
        while(!q.empty() && parent[goal] == -1) {
            int cur = q.front();
            q.pop();

            for(int next = 0; next < MAX; next++) {
                if(capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }

        // 증가 경로 없음
        if(parent[goal] == -1) {
            break;
        }

        // 증가 경로 찾음
        // 최소 잔여 용량 계산
        int minVal = INF;
        for (int idx = goal; idx != start; idx = parent[idx]) {
            int val = capacity[parent[idx]][idx] - flow[parent[idx]][idx];
            minVal = min(minVal, val);
        }

        // 도착지점 부터 되돌아가며 처리
        for (int idx = goal; idx != start; idx = parent[idx]) {
            flow[parent[idx]][idx] += minVal;
            flow[idx][parent[idx]] -= minVal;
        }

        answer += minVal;
    }

    return answer;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        char from, to;
        int cap;
        cin >> from >> to >> cap;

        int fromIdx, toIdx;

        if(from >= 'A' && from <= 'Z') fromIdx = from-'A';
        else fromIdx = from-'a'+26;
        if(to >= 'A' && to <= 'Z') toIdx = to-'A';
        else toIdx = to-'a'+26;

        capacity[fromIdx][toIdx] += cap;
        capacity[toIdx][fromIdx] += cap;
    }

    cout << EdmondsKarp();
}