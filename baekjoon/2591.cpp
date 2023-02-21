#include <iostream>
using namespace std;

char N[45];
long long d[45];

long long dp(int idx) {
    if(idx <= 1) {
        return 1;
    }
    if(d[idx] > 0) {
        return d[idx];
    }

    long long res1 = 0;
    if(N[idx] != '0') {
        res1 = dp(idx - 1);
    }

    long long res2 = 0;
    if(idx-1 >= 1) {
        string str;
        str.push_back(N[idx - 1]);
        str.push_back(N[idx]);
        int str_i = stoi(str);
        if(str_i >= 10 && str_i <= 34) {
            res2 = dp(idx-2);
        }
    }

    return d[idx] = res1 + res2;
}

int main() {
    string input; cin >> input;
    for(int i = 1; i <= input.size(); i++) {
        N[i] = input[i-1];
    }
    d[1] = 1;

    dp((int) input.size());

    cout << d[(int) input.size()];
}