#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;

bool Cal() {
    while(true) {
        if (str1.size() > str2.size()) {
            return false;
        }
        if(str2 == str1) {
            return true;
        }

        if (str2.back() == 'A') {
            str2.pop_back();
        }
        else {
            str2.pop_back();
            reverse(str2.begin(), str2.end());
        }
    }
}

int main() {
    cin >> str1 >> str2;

    cout << Cal();
}