#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l,c;
char password[16];

vector<int> num_idx;
vector<char> v;

// 최소 2개의 자음, 최소 1개의 모음이 있는지 확인
bool CheckCondition() {
    int vow = 0; // 모음
    int cons = 0; // 자음

    for(int i = 0; i < v.size(); i++) {
        // 모음인지 확인
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
            vow++;
        else // 모음이 아니라면 자음
            cons++;
    }

    if(cons >= 2 && vow >= 1)
        return true;
    else
        return false;
}

int main() {
    cin >> l >> c;
    for(int i = 0; i < c; i++) {
        cin >> password[i];
    }
    // sort
    sort(password, password+c);

    // c개중 l개를 뽑겠다
    for(int i = 0; i < c; i++) {
        if(i < l)
            num_idx.push_back(1);
        else
            num_idx.push_back(0);
    }

    do {
        for(int i = 0; i < num_idx.size(); i++) {
            if(num_idx[i] == 1) {
                //cout << password[i] << ' ';
                v.push_back(password[i]);
            }
        } //cout << '\n';

        // 조건에 맞다면 출력
        if(CheckCondition()) {
            for(auto x : v)
                cout << x;
            cout << '\n';
        }
        v.clear();
    } while(prev_permutation(num_idx.begin(), num_idx.end()));




}