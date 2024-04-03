#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

char goal[3][3];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool check(char b[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(b[i][j] != goal[i][j]) return false;
        }
    }
    return true;
}

void flip(int r, int c, char board[3][3]) {
    if(board[r][c] == '.') board[r][c] = '*';
    else board[r][c] = '.';

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;

        if(board[nr][nc] == '.') board[nr][nc] = '*';
        else board[nr][nc] = '.';
    }
}

string getStr(char board[3][3]) {
    string res;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            res.push_back(board[i][j]);
        }
    }
    return res;
}

void Print(char board[3][3]) {
    cout<<'\n';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
        } cout << '\n';
    }
}

struct Data {
    char b[3][3];
    int depth;
};

Data makeData(char b[3][3], int depth) {
    Data data;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            data.b[i][j] = b[i][j];
        }
    }
    data.depth = depth;
    return data;
}

int bfs() {
    unordered_map<string, int> um;
    queue<Data> q;
    Data data{};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            data.b[i][j] = '.';
        }
    }
    data.depth = 0;
    q.push(data);

    um["........."] = 0;

    while (!q.empty()) {
        char b[3][3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                b[i][j] = q.front().b[i][j];
            }
        }
        int depth = q.front().depth;
        q.pop();

        if(check(b)) {
            return depth;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                flip(i, j, b);
                string res = getStr(b);

                if(um.find(res) == um.end() || um[res] > depth + 1) {
                    um[res] = depth + 1;
                    q.push({makeData(b, depth + 1)});
                }

                flip(i, j, b);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> goal[i][j];
            }
        }

        cout << bfs() << '\n';
    }


}