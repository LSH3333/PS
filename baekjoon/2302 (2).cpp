#include <iostream>
using namespace std;

int N, M;
bool vip[45];
long long d[45];

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        vip[n] = true;
    }

    d[1] = 1;
    if(vip[1] || vip[2]) {
        d[2] = 1;
    }
    else {
        d[2] = 2;
    }


    for(int i = 3; i <= N; i++) {
        if(vip[i-1] || vip[i]) {
            d[i] = d[i-1];
        }
        else {
            d[i] = d[i-1] + d[i-2];
        }
    }

//    for(int i = 1; i <= N; i++) {
//        cout << d[i] << ' ';
//    }

    cout << d[N];
}