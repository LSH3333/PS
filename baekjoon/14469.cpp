#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> v;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    // 도착시간 기준 오름차순 정렬
    sort(v.begin(), v.end());

    long long time = v[0].first + v[0].second;
    for(int i = 1; i < n; i++)
    {
        if(time < v[i].first)
        {
            time = v[i].first + v[i].second;
        }
        else
        {
            time = time + v[i].second;
        }
    }

    cout << time;
}