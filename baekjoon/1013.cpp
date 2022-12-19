#include <iostream>
using namespace std;



int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        string str; cin >> str;
        int state = 0;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            if(state == 0) {
                if(c == '0') state = 1;
                else state = 3;
            }
            else if(state == 1) {
                if(c == '0') state = -1;
                else state = 2;
            }
            else if(state == 2) {
                if(c == '0') state = 1;
                else state = 3;
            }
            else if(state == 3) {
                if(c == '0') state = 4;
                else state = -1;
            }
            else if(state == 4) {
                if(c == '0') state = 5;
                else state = -1;
            }
            else if(state == 5) {
                if(c == '0') state = 5;
                else state = 6;
            }
            else if(state == 6) {
                if(c == '0') state = 1;
                else state = 7;
            }
            else if(state == 7) {
                if(c == '0') state = 8;
                else state = 7;
            }
            else if(state == 8) {
                if(c == '0') state = 5;
                else state = 9;
            }
            else if(state == 9) {
                if(c == '0') state = 1;
                else state = 3;
            }
//            cout << "state: " << c << ' ' <<  state << endl;
        }


        if(state == 2 || state == 6 || state == 7 || state == 9) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

}