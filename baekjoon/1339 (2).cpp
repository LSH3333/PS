#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int scores[27];
int convert[27];
string words[11];

void CountScore(const string &word) {
    for(int i = 0; i < word.size(); i++) {
        int o = (int)word.size() - i - 1;
        int score = (int)round(pow(10, o));
        int idx = int(word[i] - 'A');
        scores[idx] += score;
    }
}

int CalWord(const string &word) {
    int result = 0;
    for(int i = 0; i < word.size(); i++) {
        char c = word[i];
        int idx = int(c - 'A');
        int o = (int)round(pow(10,(int)word.size() - i - 1));
        result += convert[idx] * o;
    }
    return result;
}

vector<int> CalResults() {
    vector<int> results;
    for(int i = 0; i < N; i++) {
        int result = CalWord(words[i]);
        results.push_back(result);
    }
    return results;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for(int i = 0; i < N; i++) {
        CountScore(words[i]);
    }

    // {??, ???}
    vector<pair<int,int>> v;
    for(int i = 'A'-'A'; i <= 'Z'-'A'; i++) {
        if(scores[i] == 0) continue;
        v.push_back({scores[i], i});
    }
    // ???? ??
    sort(v.begin(), v.end(), greater<>());

    // ?? ?? ? convert[] ? ??
    int score = 9;
    for(auto x : v) {
        convert[x.second] = score--;
    }

    int answer = 0;
    vector<int> results = CalResults();
    for(auto x : results) {
        answer += x;
    }

    cout << answer;

}