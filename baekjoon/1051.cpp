#include <iostream>
using namespace std;

int n,m;
int rect[51][51];
int ans = 0;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool Calculate(int r, int c, int length) {
    length -= 1;

    // 기준 숫자
    int num = rect[r][c];

    if(rect[r][c+length] != num)
        return false;
    if(rect[r+length][c] != num)
        return false;
    if(rect[r+length][c+length] != num)
        return false;

    return true;
}

int main() {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &rect[i][j]);
        }
    }

    // 정사각형의 한 변의 길이
    int length = 1;
    // 정사각형의 한변의 길이는 n,m중 작은값까지만 가능하다
    while(length <= min(n,m)) {
        // rect[0][0]부터 기준점으로해서 n,m범위 벗어나지 않을때까지 기준점을
        // r과 c방향으로 이동시키며 기준점에서부터 변의길이 length로 만들어진 정사각형의 꼭짓점을 검사한다

        // row
        for(int i = 0; i < n; i++) {
            // col
            for(int j = 0; j < m; j++) {
                if(i + length > n || j + length > m)
                    break;
                // 기준점을 좌측상단으로 하는 한변의 길이 length의 정사각형의 꼭짓점을 검사한다
                if(Calculate(i,j,length)) {
                    ans = length;
                }

            }
        }
        length++;
    }

    cout << ans*ans;
}