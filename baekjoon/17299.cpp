#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000010

int N;
int arr[MAX];
int cnt[MAX];
int ans[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }


    stack<pair<int,int>> st;
    for(int i = N-1; i >= 0; i--) {
        int n = arr[i], f = cnt[n];

        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            while(!st.empty() && st.top().second <= f) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top().first;
            }
        }

        st.push({n, f});
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

}