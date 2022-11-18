#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[1000010];
int ans[1000010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> st;
    st.push(arr[N - 1]);
    ans[N-1] = -1;
    for(int i = N-2; i >= 0; i--) {
        int num = arr[i];

        while (true) {
            if(st.empty()) {
                ans[i] = -1;
                st.push(num);
                break;
            }

            int top = st.top();
            if(top > num) {
                st.push(num);
                ans[i] = top;
                break;
            }
            st.pop();
        }

    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
}