#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main() {
    int n;
    int cnt = 0;
    vector<string> v;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(int i = 0; i < v.size(); i++) {

        bool group = true;
        for(int j = 0; j < v[i].length(); j++) { /// h
            char c = v[i][j]; /// h
            bool diff = false;
            for(int k = j+1; k < v[i].length(); k++) {
                /// 기준 글자와 다른 글자가 나타났었는데 기준글자와 같은 글자가 다시 나타남
                if(diff && v[i][k] == c) { group = false; break; }
                if(c != v[i][k]) diff = true;
            }
            if(!group) break;
        }
        if(group) cnt++;
    }
    cout << cnt;

}