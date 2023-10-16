#include <iostream>
#include <vector>
using namespace std;

int N;
int flagCnt[27];

void CountFlag(const string& flag) {
    for(auto c : flag) {
        flagCnt[int(c - 'A')]++;
    }
}

void ChangeStrAlpToFlagAlp(vector<int> &cnt) {
    for(int i = 0; i <= 'Z'-'A'; i++) {
        if(cnt[i] > flagCnt[i]) {
            for(int j = 0; j <= 'Z'-'A'; j++) {
                if (flagCnt[j] > cnt[j]) {
                    cnt[i]--;
                    cnt[j]++;
                    return ;
                }
            }
        }
    }
}

bool JudgeStr(const string &flag, const string &str) {
//    cout << "---------- str: " << str << endl;

    vector<int> cnt(27, 0);
    for(auto c : str) {
        cnt[int(c-'A')]++;
    }

    if (flag.size() == str.size()) {
        ChangeStrAlpToFlagAlp(cnt);
    } else if(flag.size() > str.size()) {
        for(int i = 0; i <= 'Z'-'A'; i++) {
            if (flagCnt[i] > cnt[i]) {
                cnt[i]++; break;
            }
        }
    } else {
        for(int i = 0; i <= 'Z'-'A'; i++) {
            if(flagCnt[i] < cnt[i]) {
                cnt[i]--; break;
            }
        }
    }

    // ?? ???? ??
    for(int i = 0; i <= 'Z'-'A'; i++) {
        if(cnt[i] != flagCnt[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int answer = 0;
    string flag;

    cin >> N >> flag;
    CountFlag(flag);

    for(int i = 0; i < N-1; i++) {
        string str; cin >> str;
        if (JudgeStr(flag, str)) {
            answer++;
        }
    }

    cout << answer;
}