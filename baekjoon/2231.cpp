#include <iostream>
using namespace std;

// num의 각 자릿수를 더한값 리턴
int sums(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    int ans=0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        // i값과 i의 각 자릿수들의 합이 n이라면 i가 생성자
        if(i + sums(i) == n) {
            ans = i;
            break;
        }
    }
    cout << ans;
}