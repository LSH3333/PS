#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<>());

    for(int i = 0; i < size; i++)
    {
        if(answer >= citations[i]) return answer;
        answer++;
    }

    return answer;
}
