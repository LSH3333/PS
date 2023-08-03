#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isAllZero(const string &str) {
    for(auto x : str){
        if(x == '1') return false;
    }
    return true;
}

string ConvertToFull(string bin) {
    string fullBin = bin;
    int idx = 2;
    while (true) {
        if (bin.length() <= idx - 1) break;
        idx *= 2;
    }

    string zero;
    for(int i = 0; i < idx - 1 - bin.length(); i++) {
        zero.push_back('0');
    }
    fullBin = zero + fullBin;
    return fullBin;
}


string ConvertToBinary(long long number) {
    string bin;
    while(number > 0) {
        if(number % 2 == 0) {
            bin.push_back('0');
        } else {
            bin.push_back('1');
        }
        number /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

bool Check(string str) {
    if(str.size() == 1 || isAllZero(str)) return true;

    int len = (int)str.size();
    if(len % 2 == 0) {
        // right
        bool res1 = Check(str.substr(len / 2));
        // root
        bool res2 = Check(str.substr(len / 2 - 1, 1));
        // left
        bool res3 = Check(str.substr(0, len / 2 - 1));
        return str[len/2-1] == '1' && (res1 && res2 && res3);
    }
    else {
        // right
        bool res1 = Check(str.substr(len / 2 + 1));
        // root
        bool res2 = Check(str.substr(len / 2, 1));
        // left
        bool res3 = Check(str.substr(0, len / 2));
        return str[len/2] == '1' && (res1 && res2 && res3);
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(auto number : numbers) {
        string bin = ConvertToBinary(number);
        string fullBin = ConvertToFull(bin);
        bool res = Check(fullBin);

        if(res) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}

int main() {
    vector<long long> numbers = {9};
    solution(numbers);
}