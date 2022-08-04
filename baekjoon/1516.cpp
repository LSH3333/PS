#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int cost[510];
int entry[510];
vector<int> edge[510];
int answer[510];

void TopologySort()
{
    // node, sum
    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(entry[i] == 0) { q.push(i); answer[i] = cost[i]; }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : edge[cur])
        {
            answer[next] = max(answer[next], answer[cur]+cost[next]);
            if(--entry[next] == 0)
            {
                q.push(next);
            }
        }
    }


}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> cost[i];

        int num = 0;
        while(true)
        {
            cin >> num; if(num == -1) break;
            edge[num].push_back(i);
            entry[i]++;
        }
    }

    TopologySort();

    for(int i = 1; i <= N; i++) cout << answer[i] << '\n';
}