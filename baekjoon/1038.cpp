#include <iostream>
#include <string>
using namespace std;

int N;
int cnt = 9;

void dfs(string &num, int depth) {
    if(depth == num.size()) {
        cnt++;
        if(cnt == N) {
            cout << num;
            exit(0);
        }
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(depth == 0 && i == 0) continue;

        if(depth == 0 || num[depth-1] > char(i+'0')) {
            string tmp = num;
            num[depth] = char(i+'0');
            dfs(num, depth + 1);
            num = tmp;
        }
        else break;
    }


}

int main() {
    cin >> N;
    if(N < 10) {
        cout << N;
        return 0;
    }
    string num = "00";
    while(num.size() < 11) {
        dfs(num, 0);
        num.push_back('0');
    }
    cout << -1;
}