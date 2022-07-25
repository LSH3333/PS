#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int prime[10010];

void CheckPrimeNumber()
{
    for(int i = 2; i <= 9999; i++) prime[i] = i;
    for(int i = 2; i * i <= 9999; i++)
    {
        if(prime[i] == 0) continue;
        for(int j = i*i; j <= 9999; j+=i) prime[j] = 0;
    }
}

int bfs(int before, int after)
{
    vector<bool> mark(10010, false);
    queue<pair<int,int>> q;
    q.push({before, 0});
    mark[before] = true;

    while(!q.empty())
    {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        string curStr = to_string(cur);

        if(cur == after) return depth;

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                char digit = (char)(j+'0');
                if(digit == curStr[i]) continue;
                string nextStr = curStr;
                nextStr[i] = digit;
                int nextInt = stoi(nextStr);

                // 소수 아님 or 이미 방문 or 1000 미만
                if(prime[nextInt] == 0 || mark[nextInt] || nextInt < 1000) continue;
                q.push({nextInt, depth+1});
                mark[nextInt] = true;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    CheckPrimeNumber();

    int T; cin >> T;
    while(T--)
    {
        int before, after; cin >> before >> after;
        int res = bfs(before, after);
        if(res == -1) cout << "Impossible" << '\n';
        else cout << res << '\n';
    }

}