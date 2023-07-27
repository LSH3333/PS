#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,0};

    deque<pair<int,int>> dq;
    int sum = 0, minLen = 10000000;
    for(int i = 0; i < sequence.size(); i++) {
        int x = sequence[i];

        sum += x;
        dq.push_back({x,i});

        // k ?? ?? ?? ? ?? ??
        while(sum > k && !dq.empty()) {
            sum -= dq.front().first;
            dq.pop_front();
        }

        if(sum == k) {
            if(dq.size() < minLen) {
                answer[0] = dq.front().second;
                answer[1] = dq.back().second;
                minLen = (int)dq.size();
            }
        }
    }


    return answer;
}

int main() {
    vector<int> sequence = {1, 1, 1, 2, 3, 4, 5};
    solution(sequence, 5);
}