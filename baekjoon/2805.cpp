#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long N, M; cin >> N >> M;
    vector<long long> v;
    for(int i = 0; i < N; i++)
    {
        int h; cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());

    long long answer = 0;
    long long left = 0, right = v.back();
    while(left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            long long tmp = v[i] - mid;
            if(tmp > 0) sum += tmp;
        }

        if(sum >= M)
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