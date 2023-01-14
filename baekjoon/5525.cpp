#include <iostream>
using namespace std;

int N, M;
string s;
int answer;

int Find(int idx, int depth) {
    if((depth % 2 == 0 && s[idx] == 'I') || (depth % 2 != 0 && s[idx] == 'O')) {
        return Find(idx + 1, depth + 1);
    }
    else {
        return idx;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> s;

    int n = N * 2 + 1;
    int idx = 0;
    while(idx < M-1) {
        for(int i = idx; i < M; i++) {
            if(s[i] == 'I') {
                int ret = Find(i, 0);
                int cnt = ret - i;
                if(cnt >= n) {
                    answer += ((cnt - n) / 2) + 1;
                }
                idx = ret;
                break;
            }
            else {
                idx = i;
            }
        }

    }

    cout << answer;
}