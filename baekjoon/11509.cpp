#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}

bool mark[1000001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    // num, idx
    vector<pair<int,int>> v(n);
//    deque<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v[i] = {num * -1, i};
    }

    sort(v.begin(), v.end(), less<>());

//    for(int i = 0; i < n; i++) cout << v[i].first << ' ' << v[i].second << endl; cout << endl;
    int answer = 0;
    while(!v.empty())
    {
        answer++;
        int h = v.front().first + 1;
        int idx = v.front().second + 1;
        v.erase(v.begin());

        auto it = v.begin();
        while(it != v.end())
        {
            it = lower_bound(it, v.end(), pair<int,int>(h,0), cmp);
            if(it == v.end()) break;
            if(it->first != h) break;
            if(it->second >= idx)
            {
                h = it->first + 1;
                idx = it->second + 1;
                it = v.erase(it);
            }
            else it++;
        }
    }

    cout << answer;
}