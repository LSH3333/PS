#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 내림차순 정렬
    sort(works.begin(), works.end(), greater<>());

    int idx = 0;
    while(n > 0)
    {
        if(idx+1 >= works.size())
        {
            works[idx]--;
            idx = 0;
            n--;
            continue;
        }

        if(works[idx] >= works[idx+1]) {works[idx]--; n--;}
        else idx++;
    }

    for(auto x : works)
    {
        if(x < 0) { cout << 0; return 0;}
        answer += x * x;
    }

    return answer;
}

int main()
{
    vector<int> works = {4,3,3};
    solution(4, works);
}