#include <iostream>
#include <string>
using namespace std;

int N, answer;
string str;
int alpCnt[30];

void Print() {
    for(int i = 0; i <= 26; i++) {
        cout << alpCnt[i] << ' ';
    } cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> str;

    int l = 0, r = 0, cnt = 0;
    for(l = 0; l < str.size(); l++) {
        while(r < str.size()) {
            int idx = int(str[r] - 'a');
            if(alpCnt[idx] == 0) {
                if(cnt+1 > N) break;
                cnt++;
            }
            alpCnt[idx]++;
            r++;
        }

        answer = max(answer, r-l);

        alpCnt[int(str[l]-'a')]--;
        if(alpCnt[int(str[l]-'a')] == 0) {
            cnt--;
        }
    }

    cout << answer;
}