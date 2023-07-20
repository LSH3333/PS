#include <iostream>
#include <string>
using namespace std;

int d[1010][1010];

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                if(i-1 >= 0 && j-1 >= 0) {
                    d[i][j] = d[i-1][j-1] + 1;
                }
                else {
                    d[i][j] = 1;
                }
            }
            else {
                int val1=0, val2=0;
                if(i-1 >= 0) val1 = d[i-1][j];
                if(j-1 >= 0) val2 = d[i][j - 1];
                d[i][j] = max(val1, val2);
            }
        }
    }

    cout << d[str1.size() - 1][str2.size() - 1];
}