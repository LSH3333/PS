#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool findCapital(const string &str) {
    for(auto c : str) {
        if(c >= 'A' && c <= 'Z') return true;
    }
    return false;
}

// -1:error, 0:cpp, 1:java
int findLangType(const string &str) {
    if (str.front() == '_' || (str.front() >= 'A' && str.front() <= 'Z')
        || str.back() == '_') {
        return -1;
    }

    if(str.find("__") != string::npos) {
        return -1;
    }

    int pos = str.find('_');

    // ???? _ ? ????? ???? ???? ?? error
    if(pos != string::npos && findCapital(str)) {
        return -1;
    }

    // cpp
    if(pos != string::npos) {
        // _ ?? ??? ?? ??
        if (pos + 1 < str.size() && str[pos + 1] >= 'A' && str[pos + 1] <= 'Z') {
            return -1;
        }
        else {
            return 0;
        }
    }
        // java
    else {
        return 1;
    }
}

string javaToCpp(const string &str) {
    string res;
    for(auto c : str) {
        if(c >= 'A' && c <= 'Z') {
            res.push_back('_');
            res.push_back(tolower(c));
        }
        else {
            res.push_back(c);
        }
    }
    return res;
}

string cppToJava(const string &str) {
    string res;
    for(int i = 0; i < (int)str.size(); i++) {
        if(str[i] == '_') continue;
        if (i-1 >= 0 && str[i - 1] == '_') {
            res.push_back(toupper(str[i]));
        } else {
            res.push_back(str[i]);
        }
    }
    return res;
}

int main() {
    string str; cin >> str;

    int langType = findLangType(str);

    if(langType == -1) {
        cout << "Error!";
    }
    else if (langType == 0) {
        cout << cppToJava(str);
    }
    else {
        cout << javaToCpp(str);
    }
}