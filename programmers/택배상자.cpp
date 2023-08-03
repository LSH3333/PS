#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> q;
    for(auto x : order) {
        q.push(x);
    }
    stack<int> st;

    for(int box = 1; box <= order.size(); box++) {
        st.push(box);

        while (!st.empty() && !q.empty() && st.top() == q.front()) {
            st.pop();
            q.pop();
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> order = {5,4,3,2,1};
    cout << solution(order);
}