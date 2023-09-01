#include <iostream>
using namespace std;

// S(k-1) + o*(k+2) + S(k-1)
void Moo(int N, int k, int prevLen) {
    int len = prevLen + (k + 3) + prevLen;

    if(N <= 3) {
        if(N == 1) cout << "m";
        else cout << "o";
        return;
    }

    // ?? ???? ?? ? ??
    if(N <= len) {
        // ??? ??? ? ??? ??
        if(N == prevLen+1) {
            cout << "m";
            return;
        }
            // ??? ??? ??? ??? ??
        else if(N <= prevLen + (k + 3)) {
            cout << "o";
            return;
        }
            // ?? S(k-1) ??? ?? ?? ??
        else {
            Moo(N-(prevLen+k+3), 0, 0);
        }
    }
        // ?? ???? ?? ? ??
    else {
        // ?? ??? ??
        Moo(N, k+1, len);
    }
}

int main() {
    int N;
    cin >> N;
    Moo(N, 0, 0);
}