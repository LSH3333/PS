#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string,int> m;

    for(auto x : clothes) m[x[1]]++;

    for(auto x : m)
    {
        answer *= x.second + 1;
    }

    return answer-1;
}