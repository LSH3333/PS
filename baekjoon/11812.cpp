#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long N, K, Q;

long long GetHeight(long long n) {
    if(n==1) return 0;

    long long total = 1;
    long long h = 1;
    while(true) {
        total += (long long)pow(K, h++);
        if(n <= total) break;
    }
    return h-1;
}

long long GetParent(long long n) {
    long long mod = n % K;
    long long parent = n / K;
    if(mod >= 2) {
        parent++;
    }
    return parent;
}

void MakeHeightSame(long long &n1, long long &n2, long long &answer) {
    long long h1 = GetHeight(n1), h2 = GetHeight(n2);
    answer = abs(h1-h2);
//    cout << "h1,h2 = " << h1 << ' ' << h2 << endl;
    if(h1 == h2) return;

    if(h1 > h2) {
        for(int i = 0; i < h1-h2; i++) {
            n1 = GetParent(n1);
        }
    } else {
        for(int i = 0; i < h2-h1; i++) {
            n2 = GetParent(n2);
        }
    }
}

// ?? ?? ?? ??
long long FindCommonParent(long long node1, long long node2) {
    long long depth = 0;
    while(node1 != node2) {
        node1 = GetParent(node1);
        node2 = GetParent(node2);
        depth++;
    }
    return depth*2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> Q;
    for(int i = 0; i < Q; i++) {
        long long n1, n2; cin >> n1 >> n2;
        long long answer;
        // K=1 ? ?? ?? ?? ??
        if(K == 1) {
            cout << abs(n1-n2) << '\n';
        }
        else {
            MakeHeightSame(n1, n2, answer);
            answer += FindCommonParent(n1, n2);
            cout << answer << '\n';
        }
    }
}