#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    cin >> s;
    vector<string> v = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

    // looping string s
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=') {
            cnt++;
            i += 2;
            continue;
        }
        // looping vector v
        bool trig = false;
        for(int j = 0; j < v.size(); j++) {
            if(s[i] == v[j][0] && s[i+1] == v[j][1]) {
                cnt++;
                i++;
                trig = true;
                break;
            }
        }
        if(!trig) cnt++;
    }
    cout << cnt << endl;
}