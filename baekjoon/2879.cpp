#include <iostream>
using namespace std;

int N, answer;
int goal[1010];
int arr[1010];
int sub[1010];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> goal[i];
    }

    for(int i = 0; i < N; i++) {
        sub[i] = arr[i] - goal[i];
    }

    bool hasZero = true;
    while(hasZero) {
        hasZero = false;
        for(int i = 0; i < N; i++) {
            if(sub[i] == 0) continue;
            hasZero = true;
            int minVal = sub[i];

            for(int j = i+1; j <= N; j++) {
                // ??? ?? or sub[j] = 0 ? ??
                if(sub[i] * sub[j] <= 0) {
                    answer += abs(minVal);

                    for(int k = i; k < j; k++) {
                        sub[k] -= minVal;
                    }
                    i = j-1;
                    break;
                }
                else {
                    if (abs(sub[j]) < abs(minVal)) {
                        minVal = sub[j];
                    }
                }
            }
        }
    }

    cout << answer;
}