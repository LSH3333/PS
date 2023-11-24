#include <iostream>
using namespace std;

int N;

bool IsPrime(const string &number) {
    int n = stoi(number);
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(string &number) {
    if(number.size() == N) {
        cout << number << '\n';
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(number.empty() && i == 0) continue;
        char c = char(i + '0');
        number.push_back(c);
        if (IsPrime(number)) {
            dfs(number);
        }
        number.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    string number;
    dfs(number);

}