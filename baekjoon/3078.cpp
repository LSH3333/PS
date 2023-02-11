#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N, K;
vector<int> ranks[21];

long long mark[300010];

long long CalPairs(int strLen) {
    memset(mark, 0, sizeof(mark));

    for(int i = 0; i < ranks[strLen].size()-1; i++) {
        int rank = ranks[strLen][i];
        int rank2 = ranks[strLen][i+1];
        for(int j = rank; j < rank2; j++) {
            mark[j] = i+1;
        }
    }
    for(int i = ranks[strLen].back(); i <= 300000; i++) {
        mark[i] = (int) ranks[strLen].size();
    }

    long long ret = 0;
    for (auto rank: ranks[strLen]) {
        if(rank+K > 300000) {
            ret += mark[300000] - mark[rank];
        }
        else {
            ret += mark[rank+K] - mark[rank];
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        string s; cin >> s;
        ranks[s.size()].push_back(i);
    }

    long long answer = 0;
    for(int i = 2; i <= 20; i++) {
        if(ranks[i].size() >= 2) {
            answer += CalPairs(i);
        }
    }

    cout << answer;
}