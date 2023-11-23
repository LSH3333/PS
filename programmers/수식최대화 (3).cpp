#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<string,char>> v;

void Divide(const string &expression) {
    stringstream ss(expression);
    char token;
    string number;
    while(ss >> token) {
        if (token >= '0' && token <= '9') {
            number.push_back(token);
        } else {
            v.push_back({number, token});
//            exps.push_back(token);
            number.clear();
        }
    }
    v.push_back({number, 'q'});
}

long long Calculation(const string &n1, const string &n2, char op) {
    long long num1 = stol(n1), num2 = stol(n2);
    if (op == '+') {
        return num1+num2;
    } else if (op == '-') {
        return num1-num2;
    } else {
        return num1*num2;
    }
}

long long Cal(vector<char> exps) {
    vector<pair<string,char>> tmp = v;
    for(auto target : exps) {

        while(true) {
            bool found = false;
            for(int i = 0; i < tmp.size()-1; i++) {
                string num = tmp[i].first;
                char op = tmp[i].second;

                if (op == target) {
                    found = true;
                    long long res = Calculation(tmp[i].first, tmp[i+1].first, op);
                    tmp[i] = {to_string(res), tmp[i + 1].second};
                    tmp.erase(tmp.begin()+i+1);
                    break;
                }
            }
            if(!found) break;
        }
    }


    long long result = abs(stol(tmp.front().first));
    return result;
}

long long solution(string expression) {
    long long answer = -1;

    Divide(expression);

    vector<char> exps = {'*', '-', '+'};
    sort(exps.begin(), exps.end());
    do {
//        for(auto x : exps) {
//            cout << x << ' ';
//        } cout << endl;
        long long result = Cal(exps);
//        cout << result << endl;
        if(result > answer) {
            answer = result;
        }
    } while (next_permutation(exps.begin(), exps.end()));


    return answer;
}

int main() {
    string expression = "50*6-3*2";
    solution(expression);
}