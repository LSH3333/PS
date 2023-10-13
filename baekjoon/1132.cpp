#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;

long long alp[11];
int given[11]; // 0? ?? ?? ???
string numbers[51];
bool aloneAlp[11];

void CalAlp(const string &str) {
    int len = (int)str.size();
    for(int i = len-1; i >= 0; i--) {
        char c = str[i];
        int idx = int(c - 'A');
        alp[idx] += (long long)round(pow(10, (len-1)-i));
    }
}

long long Cal(const string &str) {
    long long res = 0;
    int len = (int)str.size();
    for(int i = len-1; i >= 0; i--) {
        char c = str[i];
        int idx = int(c - 'A');
        res += given[idx] * (long long) round(pow(10, (len - 1) - i));
    }
    return res;
}

vector<pair<long long, int>> ProcessAlones() {
    vector<pair<long long, int>> v;
    for(int i = 0; i < 10; i++) {
        v.push_back({alp[i], i});
    }
    // ???? ?? ???? ??
    sort(v.begin(), v.end(), greater<>());

    // ??? ?? 0? ?? ?? ??? ??,
    // 0? ?? ?? ??? ?? insert ?
    int s;
    for(s = (int)v.size()-1; s >= 0; s--) {
        if(!aloneAlp[v[s].second]) {
            break;
        }
    }

    vector<pair<long long, int>> tmp(v.begin()+s+1, v.end());

    for(int i = s+1; i < 10; i++) {
        v.pop_back();
    }
    v.insert(v.begin() + s, tmp.begin(), tmp.end());

    return v;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        numbers[i] = str;
        aloneAlp[int(char(str.front())-'A')] = true;
        // ??? ???? ??
        CalAlp(str);
    };

    // {?, ??? ???}
    // 0? ?? ?? ??? ???? ??? ??
    vector<pair<long long, int>> v = ProcessAlones();



    // ? ???? ?? ??
    int number = 9;
    for(auto x : v) {
        int idx = x.second;
        given[idx] = number--;
    }


    // ?? ??
    long long answer = 0;
    for(int i = 0; i < N; i++) {
        string str = numbers[i];
        answer += Cal(str);
    }

    cout << answer;


}