#include <iostream>
//#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

int N, M;
unordered_set<string> set;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string keyword;
        cin >> keyword;
        set.insert(keyword);
    }
    cin.ignore();

    for(int i = 0; i < M; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string token;
        while (getline(ss, token, ',')) {
            set.erase(token);
        }

        cout << set.size() << '\n';
    }
}