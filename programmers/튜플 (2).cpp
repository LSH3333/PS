#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> v;
    vector<int> answer;

    // ?? ??
    vector<string> tmp;
    string seq;
    bool getNum = false;
    for(int i = 1; i < s.size()-1; i++) {
        if (s[i] == '{') {
            getNum = true;
        } else if (s[i] == '}') {
            getNum = false;
            tmp.push_back(seq);
            seq.clear();
        }
        else {
            if(getNum) {
                seq.push_back(s[i]);
            }
        }
    }

    for(auto x : tmp) {
        stringstream ss(x);
        string token;
        vector<int> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(stoi(token));
        }

        v.push_back(tokens);
    }

    //
    sort(v.begin(), v.end(), cmp);

    set<int> st;
    for(auto x : v) {
        for(auto y : x) {
            // ?? ??
            if(st.find(y) == st.end()) {
                st.insert(y);
                answer.push_back(y);
                break;
            }
        }
    }

    return answer;
}

int main() {
    string s ="{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
}