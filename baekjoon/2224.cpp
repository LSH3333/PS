#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N;
vector<int> edges[130];
//vector<pair<char,char>> answers;
set<pair<char,char>> answer;

void dfs(string &res, int cur) {
    res.push_back(char(cur));

    for(int i = 0; i < res.size()-1; i++) {
//        answers.push_back({res[i], res.back()});
        answer.insert({res[i], res.back()});
    }

    for (auto next: edges[cur]) {
        dfs(res, next);
    }
}

int main() {
//    cout << int('a') << ' ' << int('z') << endl;
//    cout << int('A') << ' ' << int('Z') << endl;

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        char p = line.front(), q = line.back();
        edges[int(p)].push_back(int(q));
    }

    for(int i = 'A'; i <= 'Z'; i++) {
        string res;
        dfs(res, i);
    }
    for(int i = 'a'; i <= 'z'; i++) {
        string res;
        dfs(res, i);
    }

    for(auto x : answer) {
        cout << x.first << " => " << x.second << '\n';
    }

//    sort(answers.begin(), answers.end());
//    answers.erase(unique(answers.begin(), answers.end()), answers.end());
//
//    cout << answers.size() << '\n';
//    for(auto x : answers) {
//        cout << x.first << " => " << x.second << '\n';
//    }
}