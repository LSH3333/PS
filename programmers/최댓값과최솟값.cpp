#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    stringstream ss(s);
    string token;
    while(ss >> token)
    {
        v.push_back(stoi(token));
    }

    sort(v.begin(), v.end());

    answer = to_string(v.front()) + ' ' + to_string(v.back());

    return answer;
}