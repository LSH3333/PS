#include <iostream>
#include <string>
using namespace std;

bool IsVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

bool FirstCheck(const string &password) {
    for (auto x: password) {
        if(IsVowel(x)) {
            return true;
        }
    }
    return false;
}

bool SecondCheck(const string &password) {
    for(int i = 0; i <= (int)password.size()-3; i++) {
        if(IsVowel(password[i]) && IsVowel(password[i+1]) && IsVowel(password[i+2])) {
            return false;
        }
        else if (!IsVowel(password[i]) && !IsVowel(password[i + 1]) && !IsVowel(password[i + 2])) {
            return false;
        }
    }
    return true;
}

bool ThirdCheck(const string &password) {
    for(int i = 0; i <= (int)password.size()-2; i++) {
        if(password[i] == 'e' || password[i] == 'o') continue;
        if(password[i] == password[i+1]) {
            return false;
        }
    }
    return true;
}

bool Check(const string &password) {
    if (!FirstCheck(password) || !SecondCheck(password) || !ThirdCheck(password)) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        string password; cin >> password;
        if(password == "end") break;

        if (Check(password)) {
            cout << "<" << password << ">" << " is acceptable.\n";
        } else {
            cout << "<" << password << ">" << " is not acceptable.\n";
        }
    }
}