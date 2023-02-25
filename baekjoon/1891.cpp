#include <iostream>
#include <cmath>
using namespace std;

// 시작 사분면 위치
long long beginR, beginC;
// 도착한 사분면 위치
long long endR, endC;

// 사분면 정보로 좌표 찾음
void FindPos(const string &ip, int idx, long long len, long long _r, long long _c) {
    if(idx >= ip.size()) {
        beginR = _r;
        beginC = _c;
        return;
    }

    // 사분면
    int pos = ip[idx] - '0';

    if(pos == 1) {
        FindPos(ip, idx+1, len/2, _r, _c + len / 2);
    }
    else if(pos == 2) {
        FindPos(ip, idx+1, len/2, _r, _c);
    }
    else if(pos == 3) {
        FindPos(ip, idx+1, len/2, _r + len / 2, _c);
    }
    else {
        FindPos(ip, idx + 1, len / 2, _r + len / 2, _c + len / 2);
    }
}


string answer;
// 좌표 정보로 사분면 찾음
void FindQuadrant(long long len, long long _r, long long _c) {
    if(len == 1) {
        return;
    }

    long long subR = endR  - _r;
    long long subC = endC - _c;

    // 2
    if(subR < len/2 && subC < len/2) {
        answer.push_back('2');
        FindQuadrant(len/2, _r, _c);
    }
    // 1
    else if(subR < len/2 && subC >= len/2) {
        answer.push_back('1');
        FindQuadrant(len / 2, _r, _c + len / 2);
    }
    // 3
    else if(subR >= len/2 && subC < len/2) {
        answer.push_back('3');
        FindQuadrant(len/2, _r + len / 2, _c);
    }
    else {
        answer.push_back('4');
        FindQuadrant(len / 2, _r + len / 2, _c + len / 2);
    }
}

int main() {
    int d;
    long long toRight, toUp;
    string ip;
    cin >> d >> ip;
    cin >> toRight >> toUp;

    long long len = (long long) pow(2, ip.size());
    FindPos(ip, 0, len, 0, 0);

    // 도착한 사분면 위치
    endR = beginR + toUp*-1;
    endC = beginC + toRight;

    // 존재하지 않는 사분면인 경우  
    if(endR < 0 || endR >= len || endC < 0 || endC >= len) {
        cout << -1;
        return 0;
    }

    FindQuadrant(len, 0, 0);
    cout << answer;
}