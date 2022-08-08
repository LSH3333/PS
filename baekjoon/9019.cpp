#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int DFunc(int n)
{
    n *= 2;
    return n % 10000;
}

int SFunc(int n)
{
    n -= 1;
    if(n == -1) n = 9999;
    return n;
}

int LFunc(int n)
{
    n = (n % 1000) * 10 + (n / 1000);
    return n;
}

int RFunc(int n)
{
    n = (n % 10) * 1000 + (n / 10);
    return n;
}

string bfs(int A, int B)
{
    queue<pair<int,string>> q;
    vector<bool> mark(10001, false);
    q.push({A, ""});
    mark[A] = true;

    while(!q.empty())
    {
        int cur = q.front().first;
        string path = q.front().second;
        q.pop();

        if(cur == B) return path;

        int res = DFunc(cur);
        if(!mark[res])
        {
            mark[res] = true;
            q.push({res, path+"D"});
        }

        res = SFunc(cur);
        if(!mark[res])
        {
            mark[res] = true;
            q.push({res, path+"S"});
        }

        res = LFunc(cur);
        if(!mark[res])
        {
            mark[res] = true;
            q.push({res, path+"L"});
        }

        res = RFunc(cur);
        if(!mark[res])
        {
            mark[res] = true;
            q.push({res, path+"R"});
        }
    }

}

int main()
{

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--)
    {
        int A, B; cin >> A >> B;
        cout << bfs(A, B) << '\n';
    }

}