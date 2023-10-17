#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string input;

string ConvertToDec(const string &s) {
    string res;
    if (s.back() == 'K') {
        res.push_back('5');
    } else {
        res.push_back('1');
    }
    for(int i = 0; i < s.size()-1; i++) {
        res.push_back('0');
    }
    return res;
}

// K ?? M ??? ??? && M ??? ??? ??
string GetMax() {
    vector<string> v;
    int i = (int)input.size()-1;
    while(i >= 0) {
        if (input[i] == 'K') {
            string tmp;
            tmp.push_back(input[i--]);
            if(i < 0) { v.push_back(tmp); break;}
            while (i >= 0 && input[i] != 'K') {
                tmp.push_back(input[i--]);
            }
            reverse(tmp.begin(), tmp.end());
            v.push_back(tmp);
        } else {
            v.push_back("M");
            i--;
        }
    }


//    for(auto x : v) {
//        cout << x << ' ';
//    } cout << endl;

    string result;
    for(i = (int)v.size()-1; i >= 0; i--) {
        result += ConvertToDec(v[i]);
    }
    return result;
}

// K ?? M ??? ???? && M ??? ??? ???
string GetMin() {
    vector<string> v;
    int i = 0;
    while (i < input.size()) {
        if(input[i] == 'K') {
            v.push_back("K");
            i++;
        } else {
            string tmp;
            while(i < input.size() && input[i] != 'K') {
                tmp.push_back('M');
                i++;
            }
            v.push_back(tmp);
        }
    }

    string result;
    for(const auto &s : v) {
        result += ConvertToDec(s);
    }
    return result;
}

int main() {
    cin >> input;

    cout << GetMax() << '\n';
    cout << GetMin();
}