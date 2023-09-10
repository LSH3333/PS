#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, K;
int a[10];

string ReverseStr(const string &str, int idx) {
    string res = str;
    reverse(res.begin()+idx, res.begin()+idx+K);
    return res;
}

int bfs(const string &str, const string &goal) {
    unordered_map<string, bool> mp;
    queue<pair<string,int>> q;
    mp[str] = true;
    q.push({str, 0});

    while (!q.empty()) {
        string cur = q.front().first;
        int depth = q.front().second;
        q.pop();


        if(cur == goal) {
            return depth;
        }

        for(int i = 0; i <= N-K; i++) {
            string next = ReverseStr(cur, i);
            if(mp.find(next) != mp.end()) continue;
            mp[next] = true;
            q.push({next, depth + 1});
        }
    }

    return -1;
}

int main() {
    string str;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        str.push_back(char(a[i] + '0'));
    }

    string goal;
    for(int i = 1; i <= N; i++) {
        goal.push_back(char(i + '0'));
    }


    cout << bfs(str, goal);
}