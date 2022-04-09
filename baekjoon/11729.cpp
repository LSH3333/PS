#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
int depth;

void Hanoi(int num, int from, int by, int to)
{
    depth++;
    if(num == 1)
    {
//        cout << from << ' ' << to << '\n';
        v.push_back({from, to});
        return;
    }
    // n-1개의 원반을 1에서 2로 (3을 거쳐)
    Hanoi(num-1, from, to, by);
    // 가장 큰 원반을 1에서 3으로 (2를 거쳐)
//    cout << from << ' ' << to << '\n';
    v.push_back({from, to});
    // n-1개를 3으로
    Hanoi(num-1, by, from, to);
}

int main()
{
    int n; cin >> n;
    Hanoi(n, 1, 2, 3);
    cout << depth << '\n';
    for(auto x : v) cout << x.first << ' ' << x.second << '\n';
}