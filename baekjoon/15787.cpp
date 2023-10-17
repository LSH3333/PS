#include <iostream>
#include <set>
#include <string>
using namespace std;

#define MAX 100000
int N, M;
string trains[MAX+1];

void Init() {
    for(int i = 1; i <= N; i++) {
        trains[i] = "000000000000000000000";
    }
}

void op1(int train, int seat) {
    trains[train][seat] = '1';
}

void op2(int train, int seat) {
    trains[train][seat] = '0';
}

void op3(int train) {
    for(int i = 20; i > 0; i--) {
        trains[train][i] = trains[train][i-1];
    }
    trains[train][1] = '0';
}

void op4(int train) {
    for(int i = 1; i < 20; i++) {
        trains[train][i] = trains[train][i+1];
    }
    trains[train][20] = '0';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<string> st;

    cin >> N >> M;
    Init();
    for(int i = 0; i < M; i++) {
        int op, train, seat;
        cin >> op;

        if(op == 1) {
            cin >> train >> seat;
            op1(train, seat);
        } else if(op == 2) {
            cin >> train >> seat;
            op2(train, seat);
        } else if(op == 3) {
            cin >> train;
            op3(train);
        } else {
            cin >> train;
            op4(train);
        }
    }

    for(int train = 1; train <= N; train++) {
        st.insert(trains[train]);
    }

    cout << st.size();
}