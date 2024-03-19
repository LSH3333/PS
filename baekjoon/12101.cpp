#include <iostream>
#include <vector>
using namespace std;

int N, K, cnt;
bool flag;

void dfs(vector<int> &v, int sum) {
    if(sum > N) return;
    if(flag) return;
    if(sum == N) {
        cnt++;
        if(cnt == K) {
            flag = true;
            for(int i = 0; i < v.size()-1; i++) {
                cout << v[i] << '+';
            }
            cout << v.back();
        }
        return;
    }

    for(int i = 1; i <= 3; i++) {
        v.push_back(i);
        dfs(v, sum+i);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    vector<int> v;

    dfs(v,0);

    if(!flag) cout << -1;
}