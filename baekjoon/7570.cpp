#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000001];
int pos[1000001];
int d[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }


    for(int i = 1; i <= N; i++) {
        if (pos[i - 1] < pos[i]) {
            d[i] = d[i-1] + 1;
        }
        else {
            d[i] = 1;
        }
    }

    int lis = 0;
    for(int i = 1; i <= N; i++) {
        lis = max(lis, d[i]);
    }

    cout << N-lis;
}