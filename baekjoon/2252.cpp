#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 32001

int N, M;
vector<int> graph[MAX];
int mark[MAX];

void TopologySort()
{
    vector<int> answer;
    queue<int> q;

    // 진입차수 0인 노드들 큐에 삽입
    for(int i = 1; i <= N; i++) if(mark[i] == 0) q.push(i);
    // 학생수 만큼 반복
    for(int i = 1; i <= N; i++)
    {
        int curNode = q.front();
        q.pop();
        answer.push_back(curNode);
        for(int j = 0; j < graph[curNode].size(); j++)
        {
            int nextNode = graph[curNode][j];
            // 현재 노드와 다음 노드 연결 끊었을때 다음 노드의 진입차수가 0이라면 큐에 푸쉬
            if(--mark[nextNode] == 0) q.push(nextNode);
        }
    }

    // 출력
    for(auto x : answer) cout << x << ' ';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        mark[b]++; // 진입차수 증가
    }

    TopologySort();
}