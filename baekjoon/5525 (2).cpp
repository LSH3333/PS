#include <iostream>
#include <string>
using namespace std;

int N, M;
int answer;

int FindIOI(const string &str, int idx) {
    bool isI = true;
    string res;
    for(int i = idx; i < str.size(); i++) {
        if ((isI && str[i] == 'I') || (!isI && str[i] == 'O')) {
            res.push_back(str[i]);
        } else {
            break;
        }
        isI = !isI;
    }

    if(!res.empty() && res.back() == 'O') res.pop_back();
    int iCnt = (int)res.size() / 2 + 1;
    if(iCnt > N) {
        answer += iCnt - N;
    }
    return (int) res.size();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string str; cin >> str;

    for(int i = 0; i < str.size(); ) {
        if (str[i] == 'I') {
            int size = FindIOI(str, i);
            i += size;
        } else {
            i++;
        }
    }
    cout<< answer;
}