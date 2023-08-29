#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int countryCnt[110];

struct Data {
    int country, num, score;
};

bool cmp(const Data &a, const Data &b) {
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<Data> v;
    for(int i = 0; i < N; i++) {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end(), cmp);

    int answerCnt = 0;
    for(auto x : v) {
        if(countryCnt[x.country] < 2) {
            cout << x.country << ' ' << x.num << '\n';
            countryCnt[x.country]++;
            answerCnt++;
        }
        if(answerCnt == 3) break;
    }

}