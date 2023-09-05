#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string Convert(int n) {
    string str = to_string(n);
    string res;
    for(const auto &c : str) {
        if(c == '0') { res += "zero "; }
        else if(c == '1') { res += "one "; }
        else if(c == '2') { res += "two "; }
        else if(c == '3') { res += "three "; }
        else if(c == '4') { res += "four "; }
        else if(c == '5') { res += "five "; }
        else if(c == '6') { res += "six "; }
        else if(c == '7') { res += "seven "; }
        else if(c == '8') { res += "eight "; }
        else if(c == '9') {res += "nine "; }
    }
    res.pop_back();

    return res;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<pair<string,int>> v;
    for(int i = M; i <= N; i++) {
        v.push_back({Convert(i), i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        if(i != 0 && i % 10 == 0) cout << '\n';
        cout << v[i].second << ' ';
    }
}