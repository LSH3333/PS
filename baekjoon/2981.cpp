#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// greatest common divisor
int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a%b);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // 오름차순 정렬

    // v[i]-v[i-1]
    vector<int> nums;
    for(int i = 1; i < v.size(); i++) {
        nums.push_back(v[i] - v[i - 1]);
    }

    // 최대 공약수
    int gcd = GCD(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        gcd = GCD(gcd, nums[i]);
    }

    // 최대 공약수 gcd 의 약수들
    vector<int> answer;
    for(int i = 2; i*i <= gcd; i++) {
        if(gcd % i == 0) {
            answer.push_back(i);
            answer.push_back(gcd / i);
        }
    }
    answer.push_back(gcd);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for(auto x : answer) cout << x << ' ';
}