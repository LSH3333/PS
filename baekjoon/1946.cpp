#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while(testcase--)
    {
        int n;
        cin >> n;
        // 서류등수, 면접등수
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end(), less<>());

        int out = 0;
        int minimum = v[0].second; // 서류1등의 면접등수
        for(int i = 1; i < n; i++)
        {
            // 면접등수가 minimum보다 크다는것은, 나보다 면접,서류 모두 등수 낮은사람이 있음: 탈락
            if(v[i].second > minimum)
            {
                out++;
            }
            else // 나보다 서류 등수는 높지만, 면접 등수는 낮은 사람이 있음 : 합격
            {
                minimum = v[i].second;
            }
        }
        cout << n-out << '\n';
    }
}