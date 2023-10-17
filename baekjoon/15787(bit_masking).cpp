#include <iostream>
#include <string>
#include <bitset>
#include <set>
using namespace std;

#define MAX 100000
int N, M;
bitset<20> bits[MAX+1];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<string> st;

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int op, train, seat;
        cin >> op;

        if(op == 1) {
            cin >> train >> seat;
            bits[train].set(seat-1, true);
        } else if(op == 2) {
            cin >> train >> seat;
            bits[train].set(seat-1, false);
        } else if(op == 3) {
            cin >> train;
            unsigned long long leftShifted = bits[train].to_ullong() << 1;
            bits[train] = leftShifted;
        } else {
            cin >> train;
            unsigned long long rightShifted = bits[train].to_ullong() >> 1;
            bits[train] = rightShifted;
        }
    }

    for(int train = 1; train <= N; train++) {
        st.insert(bits[train].to_string());
    }

    cout << st.size();
}