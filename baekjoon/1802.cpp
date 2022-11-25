#include <iostream>
#include <vector>
using namespace std;

bool Cal(vector<string> v) {
    int len = (int)v.front().size();
    char tmp = v.front()[len / 2];
    for(auto x : v) {
        if(x[len / 2] != tmp) {
            return false;
        }
    }
    if(v.front().size() == 1) {
        return true;
    }

    // 접을수 있는 상황
    if(tmp == '0') {
        vector<string> next;
        for(int i = (int)v.size()-1; i >= 0; i--) {
            string str;
            for(int j = (int)v.front().size()-1; j > len / 2; j--) {
                if(v[i][j] == '0') str.push_back('1');
                else str.push_back('0');
            }
            next.push_back(str);
        }

        for(int i = 0; i < v.size(); i++) {
            string str;
            for(int j = 0; j < len / 2; j++) {
                str.push_back(v[i][j]);
            }
            next.push_back(str);
        }

        return Cal(next);
    }
    else {
        vector<string> next;
        for(int i = 0; i < v.size(); i++) {
            string str;
            for(int j = 0; j < len / 2; j++) {
                str.push_back(v[i][j]);
            }
            next.push_back(str);
        }

        for(int i = (int)v.size()-1; i >= 0; i--) {
            string str;
            for(int j = (int)v.front().size()-1; j > len / 2; j--) {
                if(v[i][j] == '0') str.push_back('1');
                else str.push_back('0');
            }
            next.push_back(str);
        }

        return Cal(next);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        string N; cin >> N;
        vector<string> v;
        v.push_back(N);
        bool res = Cal(v);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }

}