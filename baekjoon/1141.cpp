#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(const string &a, const string &b) {
    return a.size() < b.size();
}

bool Check(const string &x, const string &s) {
//    cout << "x: " << x << endl;
//    cout << "s: " << s << endl;
//    cout << "x.substr: " <<  x.substr(0, (int)s.size()) << endl;

    if(x.substr(0, (int)s.size()) == s) {
        return true;
    }
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    vector<vector<string>> groups;

    for(const auto &x : v) {
//        cout << "x: " << x << endl;
        bool trigger = false;

        for(auto &group : groups) {
            bool allHead = true;
            for(const auto &s : group) {
                // x? s? ????
                if (!Check(x, s)) {
                    allHead = false;
                    break;
                }
            }
            if(allHead) {
                group.push_back(x);
                trigger = true;
            }
        }

        if (!trigger) {
            groups.push_back({x});
        }
    }


    cout << groups.size();

}