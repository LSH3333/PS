#include <iostream>
#include <string>
#include <vector>
#define INF 2000000000
#define MAX 100000
using namespace std;

struct Node
{
    int distance;
    int cur;
};

int V,E,start;

int qSize = 0;
Node q[MAX];

// 노드 삽입
void enqueue(Node arr[], Node node)
{
    int i = 0;

    // heap의 마지막에 노드 삽입
    qSize++;
    i = qSize;
    arr[i] = node;

    // 삽입한 노드를 부모노드와 비교해 heap 속성에 위배될 경우 자리 바꿈 (루트에 도달할때까지 반복)
    while(i > 1 && arr[i/2].distance > arr[i].distance)
    {
        swap(arr[i/2], arr[i]);
        i = i / 2;
    }
}

// 트리에 heap 속성을 유지시키는 작업
// 오름차순
void min_heapify(Node arr[], int i)
{
    // 현재 노드와 자식 노드를 비교해서 더 작은 값을 갖는 자식과 교환한다
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // 현재 노드 i와 자식 노드 크기 비교 (왼쪽 자식과 오른쪽 자식 중 누가 더 큰지)
    if(left <= qSize && arr[left].distance < arr[i].distance) smallest = left;
    if(right <= qSize && arr[right].distance < arr[smallest].distance) smallest = right;

    // 현재 노드보다 자식 노드에 더 큰 값이 있다면 교환하고,
    // 자식 노드 부터 heapify 진행
    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest);
    }
}

// 큐의 첫 요소 추출
Node dequeue(Node arr[])
{
    // 루트 노드를 추출하고
    Node max = arr[1];
    // heap의 마지막 노드를 루트에 배치한다
    arr[1] = arr[qSize];
    qSize--;

    // 루트 노드부터 heapify 실행한다
    min_heapify(arr, 1);

    return max;
}

void Dijkstra(vector<int> &d, vector<pair<int,int>> graph[])
{
    d[start] = 0;

    Node node = {0, start};
    enqueue(q, node);

    while(qSize > 0)
    {
        Node top = dequeue(q);
        int distance = top.distance;
        int cur = top.cur;

        if(d[cur] < distance) continue;

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextDistance = distance + graph[cur][i].second;

            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                node = {nextDistance, next};
                enqueue(q, node);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E >> start;
    // idx 정점에서 pair.first 정점으로 가는데 pair.second 비용
    vector<pair<int,int>> graph[V+1];
    for(int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    vector<int> d(V+1, INF);
    Dijkstra(d, graph);

    for(int i = 1; i <= V; i++)
    {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}