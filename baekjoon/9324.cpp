#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Check(const string &str) {
    vector<int> d(26, 0);

    for(int i = 0; i < str.size(); ) {
        char c = str[i];
        int idx = int(c-'A');
        d[idx]++;

        if(d[idx] == 3) {
            d[idx] = 0;

            if(i+1 >= str.size() || str[i+1] != c) {
                return false;
            }
            i += 2;
        }
        else {
            i++;
        }
    }
    return true;
}

int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        string str; cin >> str;
        if(Check(str)) {
            cout << "OK\n";
        } else {
            cout << "FAKE\n";
        }
    }

}