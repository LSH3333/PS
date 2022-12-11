#include <iostream>
using namespace std;

string exp;
int N;
int ans = -2147483648;

int Cal(int n1, int n2, char op) {
    if(op == '+') return n1 + n2;
    if(op == '-') return n1 - n2;
    if(op == '*') return n1 * n2;
    else return 0;
}

void dfs(int val, int idx) {
    if(idx >= N) {
        ans = max(ans, val);
        return;
    }

    char op = idx == 0 ? '+' : exp[idx - 1];
    // 괄호 묶음
    if(idx+2 < N) {
        int res = Cal(exp[idx] - '0', exp[idx + 2] - '0', exp[idx + 1]);
        dfs(Cal(val, res, op), idx+4);
    }

    // 괄호 안묶음
    dfs(Cal(val, exp[idx] - '0', op), idx + 2);
}

int main() {
    cin >> N;
    cin >> exp;

    dfs(0, 0);
    cout << ans;
}