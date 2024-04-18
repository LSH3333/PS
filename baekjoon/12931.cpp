#include <iostream>
#include <vector>
using namespace std;

int N, answer;
int arr[51];

bool check() {
    for(int i = 0; i < N; i++) {
        if(arr[i] != 0) return false;
    }
    return true;
}

bool existOdd() {
    for(int i = 0; i < N; i++) {
        if(arr[i] % 2 != 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while(true) {
        if (check()) {
            break;
        }

        if (!existOdd()) {
            for(int i = 0; i < N; i++) {
                arr[i] = arr[i] / 2;
            }
        }
        else {
            for(int i = 0; i < N; i++) {
                if(arr[i] % 2 != 0) {
                    arr[i]--;
                    break;
                }
            }
        }

        answer++;
    }

    cout << answer;
}