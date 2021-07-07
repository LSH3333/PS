#include <iostream>
using namespace std;

int a[11];
int num;
int cnt = 0;

// a[0]부터 a[idx]까지 원소들의 합 리턴
int sums(int idx) {
    int sum = 0;
    for(int i = 0; i <= idx; i++) {
        sum += a[i];
    }
    return sum;
}

void cal(int idx) {
    // base check
    if(idx > num) return;

    for(int i = 1; i <= 3; i++) {
        a[idx] = i;
        if(sums(idx) == num) cnt++;
        cal(idx+1); // 재귀호출
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> num;
        cnt = 0;
        cal(0);
        cout << cnt << '\n';
    }


}