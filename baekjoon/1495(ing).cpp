#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, S, M; cin >> N >> S >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    queue<int> q; q.push(S);
    for(int i = 0; i < N-1; i++)
    {
        int num = v[i];
        int counter = (int)q.size();
        while(counter--)
        {
            int n = q.front(); q.pop();
            if(n + num <= M)
            {
                if(n + num + v[i+1] <= M || n + num - v[i+1] >= 0) q.push(n+num);
            }
            if(n - num >= 0)
            {
                if(n - num + v[i+1] <= M || n - num - v[i+1] >= 0) q.push(n-num);
            }
        }
        // 큐가 비었다는 것은 볼륨을 높여서 낮춰도 불가능
        if(q.empty()) {cout << -1; return 0;}
    }

    int answer = 0;
    bool found = false;
    while(!q.empty())
    {
        int num = q.front(); q.pop();
        if(num + v[N-1] <= M) { answer = max(answer, num + v[N-1]); found = true;}
        if(num - v[N-1] >= 0) { answer = max(answer, num - v[N-1]); found = true;}
    }

    if(found) cout << answer;
    else cout << -1;
    
}