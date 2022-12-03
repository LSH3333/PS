#include <iostream>
#include <stack>
using namespace std;

int N;
int mark[80010];
int building[80010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    stack<pair<int,int>> st;
    for(int i = 1; i <= N; i++) {
        cin >> building[i];
    }

    int idx = N;
    while(idx >= 0) {
        if(st.empty()) {
            st.push({idx, building[idx]});
        }
        else {
            int h = building[idx];
            int sum = 0;
            while(!st.empty() && st.top().second < h) {
                sum++;
                sum += mark[st.top().first];
                st.pop();
            }
            mark[idx] = sum;
            st.push({idx, building[idx]});
        }
        idx--;
    }

    long long answer = 0;
    for(int i = 1; i <= N; i++) {
        answer += mark[i];
    }
    cout << answer;
}