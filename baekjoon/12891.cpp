#include <iostream>
using namespace std;

int S, P, answer;
int arr[1000001];
int goal[4];
int cur[4];

bool Check() {
    for(int i = 0; i < 4; i++) {
        if(cur[i] < goal[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> S >> P;
    for(int i = 0; i < S; i++) {
        char c; cin >> c;
        if(c == 'A') arr[i] = 0;
        else if(c == 'C') arr[i] = 1;
        else if(c == 'G') arr[i] = 2;
        else arr[i] = 3;
    }

    for(int i = 0; i < 4; i++) {
        cin >> goal[i];
    }

    for(int i = 0; i < P; i++) {
        cur[arr[i]]++;
    }
    if(Check()) answer++;

    for(int i = 1; i <= S-P; i++) {
        cur[arr[i-1]]--;
        cur[arr[i+P-1]]++;

        if(Check()) {
            answer++;
        }
    }

    cout << answer;
}