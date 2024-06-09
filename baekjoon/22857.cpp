#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, answer;
int arr[50010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int l=0, r=0;

    cin >> N >> K;

    bool flag = true;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(flag && arr[i] % 2 == 0) {
            l = i;
            r = i;
            answer = 1;
            flag = false;
        }
    }

    if(flag) {
        cout << 0; return 0;
    }

    int cnt = 0;
    while(r+1 < N) {
        // ??? ??
        if(arr[r+1] % 2 != 0) {
            if(cnt == K) {
                while(arr[l] % 2 == 0) {
                    l++;
                }
                l++;
                r++;
            }
            else {
                cnt++;
                r++;
            }
        }
            // ??? ??
        else {
            r++;
        }
//        cout << l << ',' << r << ' ' << cnt << endl;
        answer = max(answer, r - l + 1 - cnt);
    }

    cout << answer;
}