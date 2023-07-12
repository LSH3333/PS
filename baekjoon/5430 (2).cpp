#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

deque<int> GetInteger(string &array) {
    deque<int> dq;
    array = array.substr(1, array.size()-2);
    stringstream ss(array);
    string token;

    while (getline(ss, token, ',')) {
        int num = stoi(token);
        dq.push_back(num);
    }

    return dq;
}

bool process(char op, deque<int> &dq, bool &state) {
    if (op == 'R') {
        state = !state;
    }
    else {
        if(dq.empty()) {
            return false;
        }

        if(state) {
            dq.pop_front();
        }
        else {
            dq.pop_back();
        }
    }

    return true;
}

void Print(bool error, bool state, const deque<int> &dq) {
    string answer;

    if(error) {
        answer = "error";
    }
    else {
        answer.push_back('[');
        if(dq.empty()) {
            answer = "[]";
        }
        else {
            if(state) {
                for(int i = 0; i < (int)dq.size(); i++) {
                    string num = to_string(dq[i]);
                    answer += num;
                    answer.push_back(',');
                }
            }
            else {
                for(int i = (int)dq.size()-1; i >= 0; i--) {
                    string num = to_string(dq[i]);
                    answer += num;
                    answer.push_back(',');
                }
            }
            answer.pop_back();
            answer.push_back(']');
        }

    }

    answer.push_back('\n');
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--) {
        string P, array;
        int n;
        bool state = true; // true:?, false:?
        bool error = false;

        cin >> P >> n >> array;

        deque<int> dq = GetInteger(array);

        for(const auto &op : P) {
            if (!process(op, dq, state)) {
                error = true;
                break;
            }
        }

        Print(error,state,dq);
    }


}