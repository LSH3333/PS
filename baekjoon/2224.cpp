#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
bool edges[130][130];

void FloydWarshall() {
    for(int k = 'A'; k <= 'z'; k++) {
        if(k > 90 && k < 97) continue;
        for(int i = 'A'; i <= 'z'; i++) {
            if(i > 90 && i < 97) continue;
            for(int j = 'A'; j <= 'z'; j++) {
                if(j > 90 && j < 97) continue;
                if (!edges[i][j]) {
                    edges[i][j] = edges[i][k] && edges[k][j];
                }
            }
        }
    }
}

int main() {
//    cout << int('a') << ' ' << int('z') << endl;
//    cout << int('A') << ' ' << int('Z') << endl;

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        unsigned char p = line.front(), q = line.back();
        edges[int(p)][int(q)] = true;
        edges[int(p)][int(p)] = true;
    }

    FloydWarshall();

    vector<string> answers;
    for(int i = 'A'; i <= 'z'; i++) {
        if(i > 90 && i < 97) continue;
        for(int j = 'A'; j <= 'z'; j++) {
            if(j > 90 && j < 97) continue;
            if(i == j) continue;
            if (edges[i][j]) {
                string str;
                str.push_back(char(i));
                str += " => ";
                str.push_back(char(j));
                answers.push_back(str);
            }
        }
    }

    cout << answers.size() << '\n';
    for(const auto &ans : answers) {
        cout << ans << '\n';
    }
}