#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    return GCD(b, a%b);
}

bool CheckA(const vector<int> &arrayA, const vector<int> &arrayB, int divisor) {
    for(int i = 0; i < arrayB.size(); i++) {
        if(arrayB[i] % divisor == 0) {
            return false;
        }
    }
    return true;
}

bool CheckB(const vector<int> &arrayA, const vector<int> &arrayB, int divisor) {
    for(int i = 0; i < arrayA.size(); i++) {
        if(arrayA[i] % divisor == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    vector<int> divisorA, divisorB;
    int gcdA = arrayA.front(), gcdB = arrayB.front();
    for(int i = 1; i < arrayA.size(); i++) {
        gcdA = GCD(gcdA, arrayA[i]);
        gcdB = GCD(gcdB, arrayB[i]);
    }

    if (CheckA(arrayA, arrayB, gcdA)) {
        answer = max(answer, gcdA);
    }
    if (CheckB(arrayA, arrayB, gcdB)) {
        answer = max(answer, gcdB);
    }


    return answer;
}

int main() {
    vector<int> arrayA = {14,35,119};
    vector<int> arrayB = {18,30,102};
    solution(arrayA, arrayB);
}