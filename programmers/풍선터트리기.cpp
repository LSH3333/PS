#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;

    vector<int> l(a.size());
    vector<int> r(a.size());
    int minVal = a[0];
    for(int i = 0; i < a.size(); i++)
    {
        minVal = min(minVal, a[i]);
        l[i] = minVal;
    }
    minVal = a[a.size()-1];
    for(int i = a.size()-1; i >= 0; i--)
    {
        minVal = min(minVal, a[i]);
        r[i] = minVal;
    }
    for(int i = 0; i < a.size(); i++)
    {
        // a[i]의 좌측 최솟값 보다 크고 && a[i]의 우측 최솟값 보다 크면 불가능
        if(!((a[i] > l[i]) && (a[i] > r[i]))) answer++;
    }

    return answer;
}
