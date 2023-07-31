#include <iostream>
#include <string>
using namespace std;

int N;

int Count(const string &s, int i, bool even) {
    int res = 0;
    int l = i - 1;
    int r = even ? i : i + 1;

    while(true) {
        if(l < 0 || r >= N) break;
        if(s[l] != s[r]) break;
        res++;
        l--; r++;
    }

    return even ? res * 2 : res * 2 + 1;
}

int solution(string s) {
    int answer=0;
    N = (int) s.size();

    for(int i = 0; i < N; i++) {
        int odd = Count(s, i, false);
        int even = Count(s, i, true);
        answer = max(answer, odd);
        answer = max(answer, even);
    }

    return answer;
}

int main() {
    string s = "abacde";
    cout << solution(s);
}