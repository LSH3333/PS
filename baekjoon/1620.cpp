#include <iostream>
#include <map>
using namespace std;

int N, M;
string index[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<string,int> dic;

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        string name; cin >> name;
        dic[name] = i;
        index[i] = name;
    }

    for(int i = 0; i < M; i++) {
        string q; cin >> q;
        // ??? ??
        if (q.front() >= '0' && q.front() <= '9') {
            int number = stoi(q);
            cout << index[number] << '\n';
        }
            // ??? ???
        else {
            cout << dic[q] << '\n';
        }
    }

}