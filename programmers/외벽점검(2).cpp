#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 2000000000;
    int weakSize = weak.size();
    for(int i = 0; i < weakSize; i++) weak.push_back(weak[i] + n);

    sort(dist.begin(), dist.end());
    do {
        for(int i = 0; i < weakSize; i++)
        {
            int start = weak[i];
            int end = weak[i+weakSize-1];
            int distIdx = 0;
            while(true)
            {
                start += dist[distIdx];
                if(start >= end)
                {
                    answer = min(answer, distIdx+1);
                    break;
                }
                distIdx++;
                if(distIdx >= dist.size()) break;
                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));

    if(answer == 2000000000) return -1;
    return answer;
}