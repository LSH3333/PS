#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k)
{
    int i = 0, cnt = 0;
    int zeroCnt = 0;

    while(true)
    {
        if(food_times[i] == 0) i = (i + 1) % food_times.size();
        else
        {
            if(cnt == k) break;
            cnt++;
            food_times[i]--;
            if(food_times[i] == 0) zeroCnt++;
            if(zeroCnt == food_times.size()) return -1;
            i = (i + 1) % food_times.size();
        }
    }

    return i+1;
}
