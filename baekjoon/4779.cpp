#include <iostream>
#include <cmath>
using namespace std;


void recurse(string &str, int n, int maxLen) {
    if(n == 0) {
        return;
    }

    int len = (int)pow(3, n);

    int start = 0;
    while(start < maxLen) {
        for (int i = start + (len / 3); i < start + (len / 3) + (len / 3); i++) {
            str[i] = ' ';
        }
        start += len;
    }

    recurse(str, n-1, maxLen);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N; cin >> N;
        if(cin.eof()) break;
        string str((int)pow(3, N), '-');

        recurse(str, N, (int)pow(3, N));

        cout << str << '\n';
    }

}