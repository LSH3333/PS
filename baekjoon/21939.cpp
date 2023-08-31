#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int N, M;
int problems[MAX+10];

struct EasyCmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

struct DiffCmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

// min heap
priority_queue<pair<int,int>, vector<pair<int,int>>, EasyCmp> easy;
// max heap
priority_queue<pair<int,int>, vector<pair<int,int>>, DiffCmp> difficult;

int RecommendDiff() {
    // solved ? ?? ??? ??
    while (problems[difficult.top().second] != difficult.top().first) {
        difficult.pop();
    }
    int p = difficult.top().second;
    return p;
}

int RecommendEasy() {
    while (problems[easy.top().second] != easy.top().first) {
        easy.pop();
    }
    int p = easy.top().second;
    return p;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int p, l; cin >> p >> l;
        easy.push({l, p});
        difficult.push({l, p});
        problems[p] = l;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        string op; cin >> op;
        if(op == "recommend") {
            int x; cin >> x;
            if(x == 1) {
                cout << RecommendDiff() << '\n';
            }
            else {
                cout << RecommendEasy() << '\n';
            }
        } else if (op == "add") {
            int p, l; cin >> p >> l;
            problems[p] = l;
            easy.push({l, p});
            difficult.push({l, p});
        } else { // solved
            int p; cin >> p;
            problems[p] = 0;
        }
    }
}