#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;


int solution(int cacheSize, vector<string> cities)
{
    if(cacheSize == 0) return cities.size() * 5;

    for(auto &x : cities)
    {
        for(int i = 0; i < x.size(); i++) x[i] = tolower(x[i]);
    }

    int time = 0;
    deque<string> cache;
    for(auto city : cities)
    {
        bool hit = false;
        // hit
        for(int i = 0; i < cache.size(); i++)
        {
            if(cache[i] == city)
            {
                // 해당 도시 지움
                cache.erase(cache.begin() + i);
                cache.push_back(city); // 뒤로 푸쉬
                hit = true;
                time += 1;
                break;
            }
        }

        if(hit) continue;
        // miss
        time += 5;
        // 캐시에 자리 있을 경우
        if(cache.size() < cacheSize)
        {
            cache.push_back(city);
        }
            // 없을 경우
        else
        {
            cache.pop_front();
            cache.push_back(city);
        }
    }

    return time;
}

int main()
{
    vector<string> cities =
            {
                    "Jeju", "Pangyo", "Seoul", "NewYork", "LA"
            };
    solution(0, cities);
}