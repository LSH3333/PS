#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, C, answer;
    vector<int> v;
    cin >> N >> C;
    for(int i = 0; i < N; i++)
    {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int left = 1;
    int right = v.back() - v.front();
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 1;
        int start = v.front();
        for(int i = 1; i < N; i++)
        {
            if(mid <= v[i] - start)
            {
                cnt++;
                start = v[i];
            }
        }

        if(cnt >= C)
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answer;
}