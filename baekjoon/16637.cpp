#include <iostream>
#include <vector>
using namespace std;

int N;
int ni, oi;
int nums[21];
char ops[21];
bool visited[21];
int answer = -2147483648;

int Cal(int n1, int n2, char op) {
    if(op == '+') {
        return n1+n2;
    }
    else if (op == '-') {
        return n1 - n2;
    }
    else {
        return n1 * n2;
    }
}

int CalResult() {
    vector<int> _nums;
    vector<char> _ops;

    for(int i = 0; i < ni; ) {
        if(visited[i]) {
            _nums.push_back(Cal(nums[i], nums[i + 1], ops[i]));
            _ops.push_back(ops[i + 1]);
            i += 2;
        }
        else {
            _nums.push_back(nums[i]);
            _ops.push_back(ops[i]);
            i++;
        }
    }

    for(int i = 0; i < _nums.size()-1; i++) {
        _nums[i+1] = Cal(_nums[i], _nums[i + 1], _ops[i]);
    }

    return _nums.back();
}

void dfs(int depth, int idx, int maxDepth) {
    if(depth == maxDepth) {
        int res = CalResult();
        answer = max(answer, res);
        return;
    }

    for(int i = idx+2; i < oi; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(depth+1, i, maxDepth);
        visited[i] = false;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        char c; cin >> c;
        if(i % 2 != 0) {
            nums[ni++] = (int)(c-'0');
        }
        else {
            ops[oi++] = c;
        }
    }

    for(int i = 0; i <= oi; i++) {
        dfs(0, -2, i);
    }

    cout << answer;
}