#include <iostream>
#include <vector>
using namespace std;

int N,M;
int nums[10];
bool mark[10];
vector<int> v;

void Print() {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void DFS(int depth) {
    if(depth == M+1) {
        Print();
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(mark[i]) continue;

        mark[i] = true;
        v.push_back(nums[i]);

        DFS(depth+1);

        v.pop_back();
        mark[i] = false;
    }

}

int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        nums[i] = i;

    DFS(1);

}
