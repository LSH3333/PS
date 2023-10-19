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

    stack<pair<int,string>> st;
    string S;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int op; cin >> op;

        if(op == 1) {
            string str; cin >> str;
            S += str;
            st.push({op, str});
        }
        else if(op == 2) {
            int k; cin >> k;
            string tmp;
            while(k--) {
                tmp.push_back(S.back());
                S.pop_back();
            }
            reverse(tmp.begin(), tmp.end());
            st.push({op, tmp});
        }
        else if(op == 3) {
            int k; cin >> k;
            cout << S[k-1] << '\n';
        }
        else {
            if(st.top().first == 1) {
                int size = (int)st.top().second.size();
                while(size--) {
                    S.pop_back();
                }
                st.pop();
            }
            else {
                S += st.top().second;
                st.pop();
            }
        }
    }


    return 0;
}
