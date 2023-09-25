#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
int arr[] = {1, 5, 10, 50};
set<int> st;

void dfs(int idx, int sum, int depth) {
    if(depth == N) {
        st.insert(sum);
        return;
    }

    for(int i = idx; i < 4; i++) {
        dfs(i, sum + arr[i], depth+1);
    }
}

int main() {
    cin >> N;

    vector<int> res;
    dfs(0,0,0);
    cout << st.size();

}