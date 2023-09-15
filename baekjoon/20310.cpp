#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    int N = int(str.size());

    int zeroCnt=0, oneCnt=0;
    for(auto c : str) {
        if(c == '0') zeroCnt++;
        else oneCnt++;
    }
    zeroCnt /= 2;
    oneCnt /= 2;

    // 0 ? ???, 1 ? ??? ?? ??
    for(int i = N-1; i >= 0; i--) {
        char &c = str[i];
        if(zeroCnt == 0) break;
        if(c == '0') {
            c = '-';
            zeroCnt--;
        }
    }

    for(int i = 0; i < N; i++) {
        char &c = str[i];
        if(oneCnt == 0) break;
        if(c == '1') {
            c = '-';
            oneCnt--;
        }
    }

    string answer;
    for(auto c : str) {
        if(c != '-') {
            answer.push_back(c);
        }
    }

    cout << answer;

}