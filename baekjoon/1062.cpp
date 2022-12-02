#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
bool mark[26];
vector<string> words;
int answer;

bool CheckWord(string word) {
    for(auto x : word) {
        if(!mark[x-'a']) return false;
    }
    return true;
}

void dfs(int idx, int depth) {
    if(depth == K-5) {
        int cnt = 0;
        for(auto word : words) {
            if(CheckWord(word)) cnt++;
        }
        answer = max(answer, cnt);

        return;
    }

    for(int i = idx; i < 26; i++) {
        if(mark[i]) continue;
        mark[i] = true;
        dfs(i, depth+1);
        mark[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        string word; cin >> word;
        words.push_back(word);
    }

    // a,n,t,i,c
    mark['a'-'a'] = true;
    mark['n'-'a'] = true;
    mark['t'-'a'] = true;
    mark['i'-'a'] = true;
    mark['c'-'a'] = true;


    dfs(0, 0);

    cout << answer;
}