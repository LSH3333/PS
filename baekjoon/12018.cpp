#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    vector<int> ans;

    while(n--)
    {
        // 신청수, 수강인원
        int p,l;
        cin >> p >> l;

        vector<int> v;
        for(int i = 0; i < p; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }

        // 신청수보다 수강인원이 많으면 마일리지를 최소인 1만 넣으면된다
        if(p < l)
        {
            ans.push_back(1);
            continue;
        }

        // 마일리지 기준 내림차순 정렬
        sort(v.begin(), v.end(), greater<>());

        // l-1번째 만큼 마일리지를 넣으면 수강신청 가능
        ans.push_back(v[l-1]);

    }


    // 필요 마일리지 기준 오름차순 정렬
    sort(ans.begin(), ans.end(), less<>());

    // 보유 마일리지 내에서 몇개의 과목 수강신청 가능한지 탐색
    int sum = 0, cnt = 0;
    for(int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
        if(sum > m)
            break;
        cnt++;
    }

    cout << cnt;
}