#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    while(left <= right)
    {
        int mid = (left + right) / 2;
        bool possible = true;
        int cnt = 0; // 물에 잠긴 연속된 돌다리의 수
        for(int i = 0; i < stones.size(); i++)
        {
            if(stones[i] < mid) cnt++;
            else cnt = 0;
            // 물에 잠긴 연속된 돌다리수가 k개가 되면 더이상 건널수 없음
            if(cnt >= k) { possible = false; break; }
        }

        // mid명이 건널수 없으면 줄임
        if(!possible)
        {
            right = mid - 1;
        }
        else // mid명이 건널수 있으면 늘림 (최댓값 구해야하므로)
        {
            answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}