#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 접두 접미 일치하는 최대 길이 저장
int pi[5010];
int answer;

// pi 테이블 생성
void MakePiTable(const string &s) {
    memset(pi, 0, sizeof(pi));
    int j = 0; // 접두
    for(int i = 1; i < s.size(); i++) { // 접미
        // 일치하지 않을 시
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        // 일치
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;

    cin >> str;

    for(int i = 0; i < str.size()-1; i++) {
        MakePiTable(str.substr(i));

        for(auto x : pi) {
            answer = max(answer, x);
        }
    }

    cout << answer;
}