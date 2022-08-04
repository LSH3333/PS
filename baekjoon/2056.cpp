#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int times[10010];
int entry[10010];
int d[10010];
vector<int> edges[10010];

void TopologySort()
{
    queue<int> q;
    for(int i = 1; i <= N; i++)
    {
        if(entry[i] == 0)
        {
            q.push(i);
            d[i] = times[i];
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto next : edges[node])
        {
            d[next] = max(d[next], d[node] + times[next]);
            entry[next]--;
            if(entry[next] == 0) q.push(next);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> times[i];
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++)
        {
            int from; cin >> from;
            edges[from].push_back(i);
            entry[i]++;
        }
    }

    TopologySort();

    int answer = 0;
    for(int i = 1; i <= N; i++) answer = max(answer, d[i]);
    cout << answer;
}