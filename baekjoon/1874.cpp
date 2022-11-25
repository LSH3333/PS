#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    stack<int> st;
    vector<char> op;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int idx = 0;
    int num = 2;
    st.push(1);
    op.push_back('+');
    while(idx < N) {
        if (st.empty() || st.top() != arr[idx]) {
            if(num > N) {
                cout << "NO";
                return 0;
            }
            st.push(num++);
            op.push_back('+');
        }
        else {
            st.pop();
            idx++;
            op.push_back('-');
        }
    }

    for(auto x : op) cout << x << '\n';
}