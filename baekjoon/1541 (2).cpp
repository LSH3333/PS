#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    vector<char> ops;
    string input;
    cin >> input;

    stringstream ss(input);
    int token;
    while(ss >> token) {
        nums.push_back(abs(token));
    }

    for(auto x : input) {
        if (x == '+' || x == '-') {
            ops.push_back(x);
        }
    }

    for(auto it = ops.begin(); it != ops.end();) {
        int idx = it - ops.begin();
        if (*it == '+') {
            nums[idx+1] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx);
            it = ops.erase(it);
        }
        else {
            it++;
        }
    }

    int answer = nums.front();
    for(int i = 1; i < nums.size(); i++) {
        answer -= nums[i];
    }

    cout << answer;


}