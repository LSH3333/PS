#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    int num = s/ n;
    int cnt = s % n;

    for(int i = 0; i < n-cnt; i++) answer.push_back(num);
    for(int i = 0; i < cnt; i++) answer.push_back(num+1);


    return answer;
}
