#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int Q;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> in, out;

    cin >> Q;
    while(Q--) {
        int op; cin >> op;
        if(op == 1) {
            int n; cin >> n;
            in.push(n);
        } else if(op == 2) {
            if (!out.empty()) {
                out.pop();
            } else {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
                out.pop();
            }
        } else {
            if (!out.empty()) {
                cout << out.top() << '\n';
            } else {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
                cout << out.top() << '\n';
            }
        }
    }

    return 0;
}
