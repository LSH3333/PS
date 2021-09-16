#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int idx;
bool cmp(const string &a, const string &b)
{
    if(a[idx] == b[idx])
        return a < b;

    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {

    idx = n;

    sort(strings.begin(), strings.end(), cmp);

    return strings;
}

