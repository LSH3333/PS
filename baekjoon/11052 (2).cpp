#include <iostream>
using namespace std;

int N;
int d[1010];
int a[1010];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    d[1] = a[1];
    for(int i = 2; i <= N; i++) {
        int maxVal = a[i];
        int left = 1, right = i - 1;
        while(left <= right) {
            maxVal = max(maxVal, d[left] + d[right]);
            left++;
            right--;
        }
        d[i] = maxVal;
    }

    cout << d[N];
}