#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

deque<string> cache;

int solution(int cacheSize, vector<string> cities)
{
    if(cacheSize == 0) return cities.size() * 5;

    // 소문자로 변경
    for(auto &x : cities)
    {
        for(int i = 0; i < x.size(); i++) x[i] = tolower(x[i]);
    }
    int time = 0;

    for(int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        // cache search
        bool hit = false;
        // cache hit
        for(int j = 0; j < cache.size(); j++)
        {
            if(cache[j] == city)
            {
                cache.erase(cache.begin()+j);
                cache.push_back(city);
                time += 1;
                hit = true;
                break;
            }
        }
        if(hit) continue;

        // cache miss
        if(cache.size() < cacheSize) // 캐시 자리 있음
        {
            cache.push_back(city);
            time += 5;
        }
        else // 캐시 자리 없음
        {
            cache.pop_front();
            cache.push_back(city);
            time += 5;
        }
    }

    return time;
}

int main()
{
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    solution(3, cities);

}