#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer[100010];

// first 기준 min heap
struct cmp
{
    bool operator() (const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
};


int main()
{
    cin >> N;
    vector<pair<int,int>> times;
    // end time, computer idx (min heap)
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    // 현재 가능한 자리 번호 (min heap)
    priority_queue<int, vector<int>, greater<>> available;
    for(int i = 0; i < N; i++)
    {
        int begin, end; cin >> begin >> end;
        times.push_back({begin, end});
    }
    sort(times.begin(), times.end());
    

    int idx = 1; // 컴퓨터
    pq.push({times.front().second, idx});
    answer[idx]++;
    for(int i = 1; i < times.size(); i++)
    {
        // 이용하려는 사람
        int begin = times[i].first, end = times[i].second;

        // 이용 끝난 사람들 pq에서 제외
        while(!pq.empty() && pq.top().first <= begin)
        {
            available.push(pq.top().second);
            pq.pop();
        }

        // 이용 가능한 자리 있으면
        if(!available.empty())
        {
            pq.push({end, available.top()});
            answer[available.top()]++;
            available.pop();
        }
        else // 없으면
        {
            pq.push({end, ++idx});
            answer[idx]++;
        }
    }


    cout << idx << '\n';
    for(int i = 1; i <= idx; i++)
    {
        cout << answer[i] << ' ';
    }
}