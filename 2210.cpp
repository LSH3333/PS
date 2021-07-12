#include <iostream>
#include <vector>
using namespace std;

char map[5][5];
int ans = 0;
// 만들 수 있는 여섯 자리의 수가 string 형태로 담긴다
vector<string> v;

// 좌우상하 이동
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void dfs(int r, int c, string str, int depth) {
    // 6자리수 만들어짐
    if(depth == 6) {
        bool same = false;
        // 6자리수가 담겨있는 벡터안에 현재 만들어진 6자리수가 str이 존재하는지 판별
        for(string x : v) {
            if(x == str) {
                same = true;
                break;
            }
        }
        // 벡터 v에 str와 같은 스트링이 없다
        if(!same) {
            // 벡터에 추가
            v.push_back(str);
            // 갯수 상승
            ans++;
        }

        return;
    }

    // str에 현재 칸 숫자 이어붙임
    str += map[r][c];
    // 4방향 탐색
    for(int i = 0; i < 4; i++) {
        int _r = r + dr[i];
        int _c = c + dc[i];
        if(_r < 0 || _r >= 5 || _c < 0 || _c >= 5) continue;

        dfs(_r, _c, str, depth+1);
    }
}

int main() {
    // input
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }

    // (0,0)부터 (4,4)까지 모든 칸에 대해 dfs 탐색 수행
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            dfs(i, j, "",0);
        }
    }

    cout << ans << '\n';

}