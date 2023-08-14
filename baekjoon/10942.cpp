#include <iostream>
using namespace std;

int N, M;
int palindrome[2010][2010];
int arr[2010];

int IsPalindrome(int s, int e) {
    if(s >= e) {
        palindrome[s][e] = 1;
        return 1;
    }
    if (palindrome[s][e] == 1) {
        return 1;
    } else if (palindrome[s][e] == -1) {
        return -1;
    }

    if (arr[s] == arr[e] && IsPalindrome(s + 1, e - 1) == 1) {
        palindrome[s][e] = 1;
        return 1;
    }
    else {
        palindrome[s][e] = -1;
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int s,e; cin >> s >> e;
        int res = IsPalindrome(s, e);
        if(res == -1) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
}