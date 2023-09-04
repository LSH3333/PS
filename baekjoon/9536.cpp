#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string GetCry(const string &op) {
    int i;
    for(i = (int)op.size()-1; i >= 0; i--) {
        if(op[i] == ' ') break;
    }

    return op.substr(i+1);
}

int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string T;
    getline(cin, T);
    int t = stoi(T);

    while(t--) {
        string str;
        getline(cin, str);

        vector<string> v;
        stringstream ss(str);
        string token;
        while(ss >> token) {
            v.push_back(token);
        }


        while(true) {
            string op;
            getline(cin, op);
            if (op.back() == '?') {
                break;
            }

            string cry = GetCry(op);

            for(int i = 0; i < v.size(); i++) {
                if(v[i] == "-") continue;
                if(v[i] == cry) {
                    v[i] = "-";
                }
            }
        }

        for(const auto &x : v) {
            if(x == "-") continue;
            cout << x << ' ';
        }
        cout << '\n';
    }




}