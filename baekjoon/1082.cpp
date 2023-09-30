#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
// {price, num}
vector<pair<int,char>> v;
int arr[12];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        v.push_back({n, char(i+'0')});
        arr[i] = n;
    }
    cin >> M;

    sort(v.begin(), v.end());


    string res;
    int sum = 0;
    // ?? ? ??? ??
    if(v.front().second == '0' && v.size() == 1) {
        cout << 0;
        return 0;
    }
    if(v.front().second == '0') {
        res.push_back(v[1].second);
        sum += v[1].first;
    } else {
        res.push_back(v[0].second);
        sum += v[0].first;
    }
    while(sum + v.front().first <= M) {
        sum += v.front().first;
        res.push_back(v.front().second);
    }

    if(sum > M) {
        cout << v.front().second;
        return 0;
    }


    for(int i = 0; i < res.size(); i++) {
        int n = int(res[i] - '0');
        for(int j = n+1; j < N; j++) {
            n = int(res[i] - '0');
            if(sum - arr[n] + arr[j] <= M) {
                res[i] = char(j + '0');
                sum = sum - arr[n] + arr[j];
            }
        }
    }

    cout << res;
}