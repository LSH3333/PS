#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int mark[10000001];

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<pair<int,int>> v;
    for(auto x : tangerine) {
        mark[x]++;
    }

    for(int i = 1; i <= 10000000; i++) {
        if(mark[i] > 0) {
            v.push_back({mark[i], i});
        }
    }

    sort(v.begin(), v.end(), greater<>());

    for(auto x : v) {
        int cnt = x.first, size = x.second;
        if(k > 0) {
            k -= cnt;
            answer++;
        }
        else {
            break;
        }
    }


    return answer;
}

int main() {
    vector<int> tangerine = {1, 1, 1, 1, 2, 2, 2, 3};
    solution(2, tangerine);
}