#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;

string bfs() {
    queue<string> q;
    int depth = 1;
    for(int i = 0; i < 10; i++) {
        string s;
        s.push_back(char(i + '0'));
        q.push(s);
    }

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if(depth == N) {
            return cur;
        }
        depth++;


        int backNum = int(cur.back() - '0');
        for(int i = 0; i < backNum; i++) {
            cur.push_back(char(i + '0'));
            q.push(cur);
            cur.pop_back();
        }
    }
    return "-1";
}

int main() {
    cin >> N;

    cout << bfs();
}