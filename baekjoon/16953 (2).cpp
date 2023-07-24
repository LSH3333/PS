#include <iostream>
using namespace std;

int A, B, answer = 1;

bool Cal() {
    while(true) {
        if(B == A) {
            return true;
        }
        if(B < A) {
            return false;
        }

        string b_str = to_string(B);
        if (b_str.back() == '1') {
            b_str.pop_back();
            B = stoi(b_str);
            answer++;
        }
        else if(B % 2 == 0) {
            B /= 2;
            answer++;
        }
        else {
            return false;
        }
    }
}

int main() {
    cin >> A >> B;

    if (Cal()) {
        cout << answer;
    }
    else {
        cout << -1;
    }

}