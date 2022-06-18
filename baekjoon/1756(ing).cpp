#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int D, N;
    cin >> D >> N;
    queue<int> pizzas;
    queue<pair<int,int>> q;
    vector<pair<int,int>> oven(D);

    for(int i = D-1; i >= 0; i--)
    {
        int n; cin >> n;
        oven[i] = {i, n};
    }
    for(int i = 0; i < N; i++) { int pizza; cin >> pizza; pizzas.push(pizza); }

    sort(oven.begin(), oven.end(), cmp);
    for(auto x : oven) q.push({x.first, x.second});

    // 가장 아래 위치 찾음
    int pizza = pizzas.front(); pizzas.pop();
    while(true)
    {
        pair<int,int> p = q.front(); q.pop();
        int idx = p.first, size = p.second;
        if(size < pizza) break;
    }

    while(pizzas.empty())
    {
        pizza = pizzas.front(); pizzas.pop();
        int idx = q.front().first, size = q.front().second;
        while(!q.empty())
        {
            idx = q.front().first, size = q.front().second;
            q.pop();
            if(size >= pizza) break;
        }

        
    }

}