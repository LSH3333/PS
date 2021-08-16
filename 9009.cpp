#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        vector<int> pibo;
        pibo.push_back(0);
        pibo.push_back(1);

        // 피보나치 수열 생성
        int num = 1;
        while(num <= n)
        {
            num = pibo[pibo.size()-2] + pibo[pibo.size()-1];
            pibo.push_back(num);
        }

        // 답 찾음
        vector<int> ans;
        int target = n;
        for(int i = pibo.size()-1; i >= 0; i--)
        {
            if(pibo[i] <= target)
            {
                ans.push_back(pibo[i]);
                target = target - pibo[i];
            }

            if(target == 0)
                break;
        }

        sort(ans.begin(), ans.end());
        for(auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }



}