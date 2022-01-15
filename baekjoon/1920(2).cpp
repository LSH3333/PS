#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M;
    vector<int> a, m, original_m;
    map<int,int> map;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        a.push_back(num);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num; cin >> num;
        map[num] = 0;
        m.push_back(num);
    }
    original_m = m;
    sort(a.begin(), a.end());
    sort(m.begin(), m.end());

    int left = 0, right = N-1;
    for(int i = 0; i < M; i++)
    {
        int target = m[i];
        int answer = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(a[mid] > target)
            {
                right = mid - 1;
            }
            else if(a[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                answer = mid;
                break;
            }
        }
        if(answer != -1) map[target] = 1;
        right = N-1;
    }

    for(int i = 0; i < original_m.size(); i++)
    {
        cout << map[original_m[i]] << '\n';
    }
}
