#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size() * 5;

    list<string> l;
    for(int i = 0; i < cities.size(); i++)
    {
        // 소문자로 통일
        for(auto &x : cities[i]) x = tolower(x);

        bool isIn = false;
        // 캐시에 존재하는지 탐색, 존재한다면 erase로 지우고 리스트의 뒤에서 push
        for(auto it = l.begin(); it != l.end(); it++)
        {
            if(*it == cities[i])
            {
                isIn = true;
                l.erase(it);
                l.push_back(cities[i]);
                answer++;
                break;
            }
        }

        // 캐시에 없음 : 리스트의 앞에서 부터 빼냄
        if(!isIn)
        {
            if(l.size() == cacheSize) l.pop_front();
            l.push_back(cities[i]);
            answer+=5;
        }
    }
    return answer;
}
