#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define MAX 1000000
int parent[MAX + 1];
int N;
int count[MAX + 1];

int GetParent(int n) {
    if(parent[n] == n) return n;
    return parent[n] = GetParent(parent[n]);
}

bool IsParentSame(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    return n1 == n2;
}

void Union(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    parent[max(n1,n2)] = min(n1,n2);
    count[min(n1, n2)] += count[max(n1, n2)];
}

void Init() {
    for(int i = 0; i <= MAX; i++) {
        parent[i] = i;
        count[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string str;
        getline(cin, str);

        vector<string> v;
        stringstream ss(str);
        string token;
        while(ss >> token) {
            v.push_back(token);
        }

        // I
        if(v.size() == 3) {
            int n1 = stoi(v[1]), n2 = stoi(v[2]);
            if(!IsParentSame(n1,n2)) {
                Union(n1, n2);
            }
        }
        // Q
        else {
            int n = stoi(v[1]);
            n = GetParent(n);
            cout << count[n] << '\n';
        }
    }
}