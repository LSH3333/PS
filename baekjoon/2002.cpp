#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, answer;
int d[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, int> mp;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        string str; cin >> str;
        mp[str] = i;
    }

    for(int i = 1; i <= N; i++) {
        string str; cin >> str;
        d[i] = mp[str];
    }

    for(int i = 1; i < N; i++) {
        for(int j = i+1; j <= N; j++) {
            if (d[j] < d[i]) {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}