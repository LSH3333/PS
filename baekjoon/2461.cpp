#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int mark[1010];


bool Check()
{
    for(int i = 0; i < N; i++)
    {
        if(mark[i] == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<pair<int,int>> v;
    int num;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> num; v.push_back({num, i});
        }
    }
    sort(v.begin(), v.end());

    int answer = v.back().first;
    int left = 0, right = 0;
    mark[v[left].second]++;
    while(right < N*M)
    {
        right++;
        if(right == N*M) break;
        mark[v[right].second]++;

        if(Check())
        {
            // 왼쪽 포인터 옮길수 있다면 옮김
            while(mark[v[left].second] > 1)
            {
                mark[v[left].second]--;
                left++;
                answer = min(answer, v[right].first - v[left].first);
            }
        }
    }
    cout << answer;
}
