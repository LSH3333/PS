#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<long long, string> mp;

string bfs(long long s, long long t) {
    if(s == t) return "0";
    queue<pair<long long, string>> q;
    q.push({s, ""});
    mp[s] = "";

    while (!q.empty()) {
        long long n = q.front().first;
        string path = q.front().second;
        q.pop();

        if(n == t) {
            return path;
        }

        if(n * n <= t && mp.find(n*n) == mp.end()) {
            mp[n * n] = path + '*';
            q.push({n*n, path + '*'});
        }
        if(n + n <= t && mp.find(n+n) == mp.end()) {
            mp[n + n] = path + '+';
            q.push({n + n, path + '+'});
        }
        if(mp.find(0) == mp.end()) {
            mp[0] = path + '-';
            q.push({0, path + '-'});
        }
        if(n != 0 && mp.find(1) == mp.end()) {
            mp[1] = path + '/';
            q.push({1, path + '/'});
        }
    }

    return "-1";
}

int main() {
    long long s,t; cin >> s >> t;

    cout << bfs(s, t);
}