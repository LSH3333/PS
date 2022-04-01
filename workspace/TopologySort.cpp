#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

int n;
// graph
vector<int> a[MAX] =
        {
                {},
                {2, 5},
                {3},
                {4},
                {6},
                {6},
                {7},
                {}
        };
// 진입차수 : 노드에 진입하는 간선의 갯수
int inDegree[MAX];

void TopologySort()
{
    vector<int> result;
    queue<int> q;

    // 진입차수가 0인 노드를 큐에 삽입
    for(int i = 1; i <= n; i++) if(inDegree[i] == 0) q.push(i);

    // 노드의 갯수만큼 반복
    for(int i = 1; i <= n; i++)
    {
        // 모든 노드들 방문전에 큐가 비었다면 싸이클이 발생한것 (위상정렬은 싸이클이 있을시 수행불가)
        if(q.empty()) return;

        int curNode = q.front();
        q.pop();
        result.push_back(curNode); // 큐에서 꺼낸 노드의 순서가 위상정렬 결과
        // 노드 curNode 에 연결된 노드들 순회
        for(int j = 0; j < a[curNode].size(); j++)
        {
            int nextNode = a[curNode][j];
            // 현재노드에 연결된 다음 노드 와의 연결을 끊었을때 다음 노드의 진입차수가 0이라면 큐에 푸쉬
            if(--inDegree[nextNode] == 0) q.push(nextNode);
        }
    }

    for(auto x : result) cout << x << ' '; cout << endl;
}

int main()
{
    n = 7;

    // 진입차수 계산
    for(int i = 1; i <= n; i++)
    {
        for(auto j : a[i]) inDegree[j]++;
    }

    TopologySort();
}