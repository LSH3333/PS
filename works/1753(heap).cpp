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

void enqueue(Node arr[], Node node)
{
    int i = 0;

    qSize++;
    i = qSize;
    arr[i] = node;

    while(i > 1 && arr[i/2].distance > arr[i].distance)
    {
        swap(arr[i/2], arr[i]);
        i = i / 2;
    }
}

// 오름차순
void min_heapify(Node arr[], int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= qSize && arr[left].distance < arr[i].distance) smallest = left;
    if(right <= qSize && arr[right].distance < arr[smallest].distance) smallest = right;

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest);
    }
}

Node dequeue(Node arr[])
{
    Node max = arr[1];
    arr[1] = arr[qSize];
    qSize--;

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