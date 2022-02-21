#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while(left <= right)
    {
        int mid = (left + right) / 2;
//        cout << left << ' ' << mid << ' ' << right << endl;
        // mid-1만큼 건넌 후 연속으로 가라앉은 돌의 갯수
        int drowned = 0, max_drowned = 0;
        for(auto stone : stones)
        {
            if(stone - (mid-1) <= 0) drowned++;
            else { max_drowned = max(max_drowned, drowned); drowned = 0; }
        }
        max_drowned = max(max_drowned, drowned);

        // mid명 건널수 없음
        if(max_drowned >= k)
        {
            right = mid - 1;
        }
        // mid명 건널 수 있음
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    solution(stones, 3);
}