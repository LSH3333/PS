#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N; cin >> N;
    deque<int> v(N);
    for(int i = 1; i <= N; i++) {
        v[i-1] = i;
    }
    if(N == 1) {
        cout << 1; return 0;
    }

    while(true) {
        v.pop_front();
        if(v.size() == 1) break;
        v.push_back(v.front());
        v.pop_front();
    }

    cout << v.front();
}