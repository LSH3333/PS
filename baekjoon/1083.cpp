#include <iostream>
using namespace std;

int N, S;
int a[51];


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> S;

    for(int i = 0; i < N; i++) {

        int maxVal = a[i], maxIdx = i;
        for(int j = i+1; (j <= i+S && j < N); j++) {
            if(a[j] > maxVal) {
                maxVal = a[j];
                maxIdx = j;
            }
        }

        if(maxVal != a[i]) {
            for(int j = maxIdx; j > i; j--) {
                swap(a[j], a[j - 1]);
                S--;
            }
        }

    }

    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
}