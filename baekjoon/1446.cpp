#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// D[i] : i까지 도달하는데 최소 거리
int d[10010];

struct Set
{
    int from, to, dist;
};

bool cmp(const Set &a, const Set &b)
{
    if(a.from == b.from) return a.to < b.to;
    return a.from < b.from;
}

int main()
{
    int N, D; cin >> N >> D;
    for(int i = 0; i < 10010; i++) d[i] = i;
    vector<Set> v(N);
    for(int i = 0; i < N; i++)
    {
        int from, to, dist; cin >> from >> to >> dist;
        v[i] = {from, to, dist};
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++)
    {
        int from = v[i].from, to = v[i].to, dist = v[i].dist;
        d[to] = min(d[to], d[from] + dist);
        int cnt = 1;
        for(int j = to+1; j <= D; j++, cnt++)
        {
            d[j] = min(d[to] + cnt, d[j]);
        }
    }

    cout << d[D];
}