#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if(cacheSize == 0) return 5 * cities.size();
    
    deque<string> deq;

    int answer = 0;
    for(auto &city : cities)
    {
        // 소문자로 통일
        for(auto &x : city) x = tolower(x);

        if(deq.empty())
        {
            deq.push_back(city);
            answer += 5;
        }
        else if(deq.size() < cacheSize)
        {
            auto it = find(deq.begin(), deq.end(), city);
            // cache hit
            if(it != deq.end())
            {
                answer += 1;
                deq.erase(it);
                deq.push_back(city);
            }
            // cache miss
            else
            {
                answer += 5;
                deq.push_back(city);
            }
        }
        else // cache 꽉차있는 상태
        {
            auto it = find(deq.begin(), deq.end(), city);
            // cache hit
            if(it != deq.end())
            {
                answer += 1;
                deq.erase(it);
                deq.push_back(city);
            }
            else // cache miss
            {
                answer += 5;
                deq.pop_front();
                deq.push_back(city);
            }
        }
    }
//    cout << answer;
    return answer;
}

int main()
{
    int cacheSize = 3;
    vector<string> cities =
            {
                    "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"
            };
    solution(cacheSize, cities);
}