#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    int name = 666;
    string s;

    cin >> n;

    while(name) {
        // 현재 숫자를 스트링으로 변환후
        s = to_string(name);

        // 문자열에 "666"이 포함되어 있다
        if(s.find("666") != -1)
            cnt++; // 카운트 증가

        if(cnt == n) {
            cout << name << '\n';
            return 0;
        }
        name++;
    }

}