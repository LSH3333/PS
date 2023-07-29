#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Comp {
    int col;

    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[col] == b[col]) {
            return a[0] > b[0];
        }
        return a[col] < b[col];
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    vector<int> res;
    int answer = 0;
    col--; row_begin--; row_end--;

    sort(data.begin(), data.end(), Comp{col});


    for(int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for (const auto &x: data[i]) {
            sum += (x % (i+1));
        }
        res.push_back(sum);
    }

    answer = res.front();
    for(int i = 1; i < res.size(); i++) {
        answer = answer xor res[i];
    }

    return answer;
}

int main() {
    vector<vector<int>> data = {
            {2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}
    };

    solution(data, 2, 2, 3);
}