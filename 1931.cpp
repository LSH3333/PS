#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<pair<long long, long long>> v;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    // second 기준 오름차순 정렬하고 second 값이 같다면 first 기준 오름차순 정렬
    sort(v.begin(), v.end(), cmp);
//    for(auto x : v)
//    {
//        cout << x.first << ' ' << x.second << endl;
//    }

    long long endTime = v[0].second;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[i].first < endTime) continue;
        cnt++;
        endTime = v[i].second;
    }

    cout << cnt;
}