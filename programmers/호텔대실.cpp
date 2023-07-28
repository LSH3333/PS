#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


struct pqCmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int ConvertToMin(const string &time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int,int>> v;
    for (auto x: book_time) {
        v.push_back({ConvertToMin(x[0]), ConvertToMin(x[1])});
    }

    sort(v.begin(), v.end());

    // second ?? min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, pqCmp> pq;
    for(auto x : v) {
        if (pq.empty()) {
            pq.push(x);
        }
        else {
            if (pq.top().second + 10 <= x.first) {
                pq.pop();
                pq.push(x);
            }
            else {
                pq.push(x);
            }
        }
        answer = max(answer, (int)pq.size());
    }

    return answer;
}

int main() {
    vector<vector<string>> book_time = {
            {"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},
            {"14:10", "19:20"},{"18:20", "21:20"}
    };
    cout << solution(book_time);
}