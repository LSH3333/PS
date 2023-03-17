#include <iostream>
#include <vector>
using namespace std;

#define MAX 200000

vector<string> words;

void Input() {
    string input;
    do {
        cin >> input;
        if(input == "-") break;
        words.push_back(input);
    } while(input != "-");
}

void CountAlp(const string &input, vector<int> &alp) {
    for(auto c : input) {
        alp[c-'A']++;
    }
}

bool IsItValid(const vector<int> &alp, const vector<int> &cnt) {
    for(int i = 'A'-'A'; i <= 'Z'-'A'; i++) {
        if(cnt[i] > alp[i]) return false;
    }
    return true;
}

void FindValidWord(const vector<int> &alp, vector<string> &valid) {

    for(const auto &word : words) {
        vector<int> cnt(26,0);

        for(auto c : word) {
            cnt[c-'A']++;
        }

        if (IsItValid(alp, cnt)) {
            valid.push_back(word);
        }
    }
}

void Count(const vector<string> &valid, const vector<int> &alp) {
    vector<int> cnt(26, 0);

    for(char c = 'A'; c <= 'Z'; c++) {
        if(alp[c-'A'] == 0) continue;
        for(const auto &word : valid) {
            for(const auto &x : word) {
                if(x == c) {
                    cnt[c-'A']++;
                    break;
                }
            }
        }
    }

    int minVal = MAX, maxVal = 0;
    for(int i = 0; i < 26; i++) {
        if(alp[i] == 0) continue;
        minVal = min(minVal, cnt[i]);
        maxVal = max(maxVal, cnt[i]);
    }

    string minAns, maxAns;
    for(char c = 'A'; c <= 'Z'; c++) {
        if(alp[c-'A'] == 0) continue;

        if(cnt[c-'A'] == minVal) {
            minAns.push_back(c);
        }
        if(cnt[c-'A'] == maxVal) {
            maxAns.push_back(c);
        }
    }

    cout << minAns << ' ' << minVal << ' ' << maxAns << ' ' << maxVal << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Input();

    string input;
    do {
        cin >> input;
        if(input == "#") break;

        vector<int> alp(26, 0);
        vector<string> valid;

        // 주어진 퍼즐판의 알파벳 갯수 카운트
        CountAlp(input, alp);
        // 퍼즐판의 문자들로 만들수 있는 단어 찾음
        FindValidWord(alp, valid);
        // 정답
        Count(valid, alp);

    } while(input != "#");


}