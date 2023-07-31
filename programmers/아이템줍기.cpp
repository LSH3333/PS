#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


bool board[200][200];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void DrawRec(const vector<int> &rec) {
    int x1 = rec[0] * 2, y1 = rec[1] * 2;
    int x2 = rec[2] * 2, y2 = rec[3] * 2;

    for(int x = x1; x <= x2; x++) {
        for(int y = y1; y <= y2; y++) {
            board[x][y] = true;
        }
    }
}

void EraseInside(const vector<int> &rec) {
    int x1 = rec[0] * 2, y1 = rec[1] * 2;
    int x2 = rec[2] * 2, y2 = rec[3] * 2;

    for(int x = x1 + 1; x < x2; x++) {
        for(int y = y1 + 1; y < y2; y++) {
            board[x][y] = false;
        }
    }
}

void MakeBoard(const vector<vector<int>> &rectangle) {
    // draw full rectangle
    for (const auto &rec: rectangle) {
        DrawRec(rec);
    }

    // erase inside of rectangle
    for (const auto &rec: rectangle) {
        EraseInside(rec);
    }
}

int bfs(int characterX, int characterY, int itemX, int itemY) {
    queue<pair<int,int>> q;
    vector<vector<int>> visited(200, vector<int>(200, 0));
    visited[characterX*2][characterY*2] = 1;
    q.push({characterX*2, characterY*2});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        if(r == itemX*2 && c == itemY*2) {
            return visited[r][c];
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr > 200 || nc < 0 || nc > 200) continue;
            if(board[nr][nc] == 0 || visited[nr][nc] > 0) continue;
            q.push({nr, nc});
            visited[nr][nc] = visited[r][c] + 1;
        }
    }

    return -1;
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    MakeBoard(rectangle);
    answer = bfs(characterX, characterY, itemX, itemY);
    answer /= 2;

    return answer;
}

int main() {
//    vector<vector<int>> rectangle = {{1, 1, 7, 4},
//                                     {3, 2, 5, 5},
//                                     {4, 3, 6, 9},
//                                     {2, 6, 8, 8}};

//    vector<vector<int>> rectangle = {{1, 1, 8, 4},
//                                     {2,2,4,9},
//                                     {3,6,9,8},
//                                     {6,3,7,7}};

    vector<vector<int>> rectangle = {{2,1,7,5},{6,4,10,10}};
    cout << solution(rectangle, 3,1,7,10);
}