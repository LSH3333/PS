#include <iostream>
#include <string>
using namespace std;

string str;
int N;
int aCnt;

int Cal(int idx) {
    int res = 0;
    for(int i = idx; i < idx+aCnt; i++) {
        if(i >= N) {
            if(str[i % N] == 'b') res++;
        } else {
            if(str[i] == 'b') res++;
        }
    }
    return res;
}

int main() {
    int answer = 2000;
    cin >> str;
    N = (int)str.size();

    for(auto c : str) {
        if(c == 'a') aCnt++;
    }

    for(int i = 0; i < N; i++) {
        int res = Cal(i);
        answer = min(answer, res);
    }

    cout << answer;
}