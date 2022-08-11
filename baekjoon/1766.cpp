#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 32010

int N, M;
vector<int> edges[MAX];
int entry[MAX];
vector<int> answer;

void TopologySort()
{
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 1; i <= N; i++)
    {
        if(entry[i] == 0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        answer.push_back(cur);

        for(auto next : edges[cur])
        {
            if(--entry[next] == 0)
            {
                pq.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        entry[b]++;
    }

    TopologySort();

    for(auto x : answer) cout << x << ' ';
}