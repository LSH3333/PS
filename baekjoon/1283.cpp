#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool mark[27];
vector<vector<string>> options;



void Find(vector<string> &option) {
    // 1
    for(auto &str : option) {
        char c = str.front();
        int idx = int(tolower(c) - 'a');
        if (!mark[idx]) {
            mark[idx] = true;
            string tmp = "[";
            tmp.push_back(c);
            tmp.push_back(']');
            string newStr = tmp + str.substr(1);
            str = newStr;
            return;
        }
    }

    // 2
    for(auto &str : option) {
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            int idx = int(tolower(c) - 'a');
            if(!mark[idx]) {
                mark[idx] = true;
                string tmp = "[";
                tmp.push_back(c);
                tmp.push_back(']');
                string newStr = str.substr(0, i) + tmp + str.substr(i+1);
                str = newStr;
                return;
            }
        }
    }
}

int main() {
    int N; cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++) {
        string str;
        getline(cin, str);

        vector<string> tmp;
        stringstream ss(str);
        string token;
        while(ss >> token) {
            tmp.push_back(token);
        }
        options.push_back(tmp);
    }

    for (auto &option: options) {
        Find(option);
    }

    for(const auto &option : options) {
        for (const auto &str: option) {
            cout << str << ' ';
        }
        cout << '\n';
    }

}