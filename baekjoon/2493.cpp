#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[500010];
int ans[500010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<pair<int,int>> st;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = N; i >= 1; i--) {
        int h = arr[i];
        if(st.empty()) {
            st.push({i, h});
        }
        else {
            while(!st.empty() && h >= st.top().second) {
                ans[st.top().first] = i;
                st.pop();
            }
            st.push({i, h});
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}