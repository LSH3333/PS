#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    long long left_r = left / n;
    long long left_c = left % n;
    long long right_r = right / n;
    long long right_c = right % n;
//    cout << left_r << ' ' << left_c << endl;
//    cout << right_r << ' ' << right_c << endl << endl;

    int r = left_r, c = left_c;
    while(true)
    {
        if(c > r) answer.push_back((r+1) + (c-r));
        else answer.push_back(r+1);
        if(r == right_r && c == right_c) break;
        if(++c >= n) { c = 0; r++; }
    }

//    for(auto x : answer) cout << x << ' ';
    return answer;
}
