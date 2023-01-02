#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[110];
bool mark[110];

void StackPush(stack<int> &st, int num) {
    if(st.empty()) {
        st.push(num);
        return;
    }
    if(st.top() == num) {
        st.pop();
    }
    else {
        st.push(num);
    }
}

void StackClear(stack<int> &st) {
    while(!st.empty()) {
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<int> answer;
    stack<int> st;
    for(int i = 1; i <= N; i++) {
        if(mark[i]) continue;
        int A = i;
        int B = arr[i];
        vector<int> chose;

        StackPush(st, A);
        StackPush(st, B);
        mark[A] = true;
        chose.push_back(A);

        while(!mark[B]) {
            StackPush(st, B);
            StackPush(st, arr[B]);
            chose.push_back(B);
            mark[B] = true;
            B = arr[B];
        }

        if(st.empty()) {
            for(auto x : chose) answer.push_back(x);
        }
        else {
            for(auto x : chose) mark[x] = false;
        }

        StackClear(st);
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(auto x : answer) cout << x << '\n';
}