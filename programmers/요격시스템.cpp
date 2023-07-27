#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), cmp);

    answer = 1;
    int hitEnd = targets.front()[1];
    for(int i = 1; i < targets.size(); i++) {
        int begin = targets[i][0], end = targets[i][1];

        if (hitEnd <= begin) {
            answer++;
            hitEnd = end;
        }
        else {
            hitEnd = min(hitEnd, end);
        }
    }

    return answer;
}

int main() {
//    vector<vector<int>> targets = {
//            {4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}
//    };
    vector<vector<int>> targets = {
            {1,2}, {1,3}, {2,5}, {3,6}, {4,8}, {8,10}
    };


    cout << solution(targets);
}