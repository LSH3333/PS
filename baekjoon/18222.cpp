#include <iostream>
using namespace std;

long long k;

long long Get(long long n) {
    long long res = 1;
    while(true) {
        if(res >= n) return res;
        res *= 2;
    }
}

void dfs(long long l, long long n, int depth) {
    if(n <= 2) {
        if(depth % 2 != 0) {
            if(n == 1) cout << 1;
            else cout << 0;
        } else {
            if(n == 1) cout << 0;
            else cout << 1;
        }
        return;
    }

    l = Get(n);
    dfs(l, l / 2 - (l - n), depth + 1);
}

int main() {
    cin >> k;
    long long l = Get(k);

    dfs(l,k,0);

}