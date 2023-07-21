#include <iostream>
using namespace std;

#define MAX 4000

int d[MAX+1][MAX+1];

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    for(int c = 0; c < str2.size(); c++) {
        for(int r = 0; r < str1.size(); r++) {
            if(str1[r] == str2[c]) {
                if(r-1 >= 0 && c-1 >= 0) {
                    d[r][c] = d[r-1][c-1] + 1;
                }
                else {
                    d[r][c] = 1;
                }
            }
        }
    }

    int answer = 0;
    for(int r = 0; r < str1.size(); r++) {
        for(int c = 0; c < str2.size(); c++) {
            answer = max(answer, d[r][c]);
        }
    }

    cout << answer;
}