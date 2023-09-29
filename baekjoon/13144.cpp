#include <iostream>
using namespace std;

int N;
long long answer;
int arr[100001];
bool d[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 1 2 3 1 2
    int l = 0, r = 0;
    for(l = 0; l < N; l++) {
        while(r < N) {
            if(d[arr[r]]) break;
            d[arr[r]] = true;
            r++;
        }

        answer += (r-l);
        d[arr[l]] = false;
    }


    cout << answer;
}