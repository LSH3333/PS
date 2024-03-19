#include <iostream>
#include <vector>
using namespace std;

int A, T, target;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> T >> target;

    vector<int> v;
    int len = 2;
    int i = 0;
    while(i < 10010) {
        v.push_back(0); // ?
        v.push_back(1); // ??
        v.push_back(0); // ?
        v.push_back(1); // ??
        // ?
        for(int j = 0; j < len; j++) {
            v.push_back(0);
        }
        // ??
        for(int j = 0; j < len; j++) {
            v.push_back(1);
        }

        i += len * 2 + 4;
        len++;
    }

    int cnt = 0;
    for(i = 0; i < 20000000; i++) {
        if(v[i] == target) {
            cnt++;
        }

        if(cnt == T) {
            cout << i % A;
            break;
        }
    }

}