#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<int,int>> v;
queue<int> colIdx;
int ans = 0;

// pair의 second 기준 오름차순 정렬
bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
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

    // second기준으로 정렬 (색깔별로 정렬)
    sort(v.begin(), v.end(), compare);


    // 하나의 색깔의 마지막 인덱스가 저장되어있는 colIdx 큐 만들기
    // 이 큐를 이용해 이후에 같은 색깔들을 first 기준 오름차순 정렬할것임
    int color = v[0].second; // 1
    for(int i = 0; i < n; i++)
    {
        if(v[i].second != color)
        {
            colIdx.push(i-1);
            color = v[i].second; // 2
        }
    }
    colIdx.push(v.size()-1);


    // first를 기준으로 같은 색들끼리 정렬한다
    int temp = 0;
    while(!colIdx.empty())
    {
        sort(v.begin() + temp , v.begin() + colIdx.front()+1);
        temp = colIdx.front()+1;
        colIdx.pop();
    }

    // 정렬된 벡터를 돌면서 화살표의 길이를 구해 더한다
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            ans += abs(v[1].first - v[0].first);
        }
        else if(i == n-1)
        {
            ans += abs(v[n-2].first - v[n-1].first);
        }
        else
        {
            int a,b;
            if(v[i-1].second != v[i].second)
                a = 999999999;
            else
                a = abs(v[i].first - v[i-1].first);

            if(v[i+1].second != v[i].second)
                b = 999999999;
            else
                b = abs(v[i].first - v[i+1].first);

            int smaller = min(a,b);
            ans += smaller;
        }
    }

    cout << ans;
}