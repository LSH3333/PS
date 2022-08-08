#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int population[11];
vector<int> edges[11];
int answer = 100000000;

bool bfs(const vector<int> &A, const vector<bool> &mark, bool b)
{
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(A.front());
    visited[A.front()] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : edges[cur])
        {
            if(visited[next] || mark[next] != b) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    for(auto x : A)
    {
        if(!visited[x]) return false;
    }
    return true;
}

bool Check(const vector<bool> &mark)
{
    vector<int> A, B;
    for(int i = 1; i <= N; i++)
    {
        if(mark[i]) A.push_back(i);
        else B.push_back(i);
    }

    if(!bfs(A, mark, true)) return false;
    if(!bfs(B, mark, false)) return false;
    return true;
}

void dfs(vector<bool> &mark, int idx, int depth, int goal)
{
    if(depth == goal)
    {
//        for(int i = 1; i <= N; i++)
//        {
//            if(mark[i]) cout << i << ' ';
//        } cout << endl;

        if(Check(mark))
        {
            int A = 0, B = 0;
            for(int i = 1; i <= N; i++)
            {
                if(mark[i]) A += population[i];
                else B += population[i];
            }
            answer = min(answer, abs(A-B));
        }

        return;
    }

    for(int i = idx; i <= N; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        dfs(mark, i, depth+1, goal);
        mark[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> population[i];
    for(int i = 1; i <= N; i++)
    {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++)
        {
            int n; cin >> n;
            edges[i].push_back(n);
        }
    }


    for(int goal = 1; goal < N; goal++)
    {
        vector<bool> mark(N+1, false);
        dfs(mark, 1, 0, goal);
    }

    if(answer == 100000000) cout << -1;
    else cout << answer;


}