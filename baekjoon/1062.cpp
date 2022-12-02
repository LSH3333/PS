#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    vector<string> words;
    vector<pair<int,char>> cnt(26);
    for(int i = 0; i < 26; i++) cnt[i].second = char('a'+i);

    for(int i = 0; i < N; i++) {
        string word; cin >> word;
        sort(word.begin(), word.end());
        word.erase(unique(word.begin(), word.end()), word.end());
        words.push_back(word);
    }

    // 각 알파벳이 몇개의 단어에 포함 되는지 카운트
    for(int i = 0; i < 26; i++) {
        char c = char('a' + i);

        for(const auto &word : words) {
            for(auto x : word) {
                if(x == c) {
                    cnt[i].first++;
                    break;
                }
            }
        }
    }
    sort(cnt.begin(), cnt.end(), greater<>());

    for(int i = 0; i < K; i++) {
        char c = cnt[i].second;

        for(auto &word : words) {
            for(auto it = word.begin(); it != word.end(); it++) {
                if(*it == c) {
                    word.erase(it);
                    break;
                }
            }
        }
    }
    for(auto x : cnt) {
        cout << x.first << ',' << x.second << "  ";
    } cout << endl;

    for(auto x : words) {
        cout << x << endl;
    }

    int answer = 0;
    for(auto x : words) {
        if(x.empty()) answer++;
    }
    cout << answer;

}