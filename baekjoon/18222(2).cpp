#include <iostream>
using namespace std;

long long dfs(long long n) {
    if(n == 1) {
        return 0;
    }

    // l는 이전 길이
    long long l = 1;
    for(l = 1; l+l < n; l+=l);
    return !dfs(n-l);
}

int main() {
    long long k; cin >> k;
    cout << dfs(k);
}