#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
bool visited[51];
bool found;

void dfs(int idx, vector<int> &res) {
    if(found) return;
    if(idx == str.size()) {
        int maxVal = 0;
        for(auto x : res ) {
            maxVal = max(maxVal, x);
        }

        if (maxVal > res.size()) {
            return;
        }
        else {
            for(auto x : res) {
                cout << x << ' ';
            }
            found = true;
            return;
        }
    }

    int n1 = stoi(str.substr(idx,1));
    if (n1 > 0 && n1 < 51 && !visited[n1]) {
        visited[n1] = true;
        res.push_back(n1);
        dfs(idx+1, res);
        res.pop_back();
        visited[n1] = false;
    }

    if(idx == str.size()-1) return;
    int n2 = stoi(str.substr(idx, 2));
    if (n2 > 0 && n2 < 51 && !visited[n2]) {
        visited[n2] = true;
        res.push_back(n2);
        dfs(idx+2, res);
        visited[n2] = false;
        res.pop_back();
    }
}

int main() {
    cin >> str;

    vector<int> res;
    dfs(0, res);

}