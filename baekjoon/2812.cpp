#include <iostream>
#include <stack>
using namespace std;

int N, K, goal;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<int> st;
    string num;
    cin >> N >> K;
    cin >> num;
    goal = N-K;

    for(int i = 0; i < N; i++) {
        int n = num[i]-'0';

        if(st.empty()) {
            st.push(n);
        }
        else {
            if(st.top() >= n) {
                if((int)st.size() >= goal) continue;
                st.push(n);
            }
            else {
                while(!st.empty() && st.top() < n && st.size()+(N-i) > goal) {
                    st.pop();
                }
                st.push(n);
            }
        }
    }

    string answer;
    while(!st.empty()) {
        char c = char(st.top()+'0');
        answer.push_back(c);
        st.pop();
    }
    for(int i = (int)answer.size()-1; i >= 0; i--) cout << answer[i];

}