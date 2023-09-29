#include <iostream>
using namespace std;

int N, Q;
bool d[1100000];

void Find(int q, int &res) {
    if(d[q]) {
        res = q;
    }
    if(q == 1){
        return;
    }
    Find(q/2, res);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < Q; i++) {
        int q; cin >> q;
        int res = 0;
        Find(q, res);
        if(res == 0) {
            d[q] = true;
        }
        cout << res << '\n';
    }

}