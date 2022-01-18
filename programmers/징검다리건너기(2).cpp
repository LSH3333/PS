#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k)
{
    int answer;

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while(left <= right)
    {
        int mid = (left + right) / 2;
        cout << left << ' ' << right << ' ' << mid << endl;
        int cnt = 0;
        bool possible = true;
        for(int i = 0; i < stones.size(); i++)
        {
            if(stones[i] - mid + 1 <= 0) cnt++;
            else cnt = 0;
            if(cnt >= k) {possible = false; break;}
        }

        if(!possible)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            answer = mid;
        }

    }

    return answer;
}