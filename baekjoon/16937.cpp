#include <iostream>
#include <vector>
using namespace std;

int H, W, N;
pair<int,int> arr[110];

// 크기 h,w 의 스티커 (r,c)에 붙일수 있는지 여부 확인
bool DoesItFit(int r, int c, int h, int w, vector<vector<bool>> &mark) {
    if(r + h - 1 >= H || c + w - 1 >= W) return false;
    for(int i = r; i < r + h; i++) {
        for(int j = c; j < c + w; j++) {
            if(mark[i][j]) return false;
        }
    }
    return true;
}

void PutSticker(int r, int c, int h, int w, vector<vector<bool>> &mark) {
    for(int i = r; i < r + h; i++) {
        for(int j = c; j < c + w; j++) {
            mark[i][j] = true;
        }
    }
}

// 크기 h,w 스티커 붙일곳 찾는다
bool TryPutSticker(int h, int w, vector<vector<bool>> &mark) {
    for(int r = 0; r < H; r++) {
        for(int c = 0; c < W; c++) {
            if(DoesItFit(r, c, h, w, mark)) {
                PutSticker(r, c, h, w, mark);
                return true;
            }
        }
    }
    return false;
}

void Print(vector<vector<bool>> &mark) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << mark[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void Init(vector<vector<bool>> &mark) {
    for(int i = 0; i < mark.size(); i++) {
        for(int j = 0; j < mark[i].size(); j++) {
            mark[i][j] = false;
        }
    }
}

bool TryPutSticker(int h1, int w1, int h2, int w2) {
    vector<vector<bool>> mark(H, vector<bool>(W, false));

    if(TryPutSticker(h1, w1, mark) && TryPutSticker(h2, w2, mark)) return true;
    Init(mark);

    if(TryPutSticker(w1, h1, mark) && TryPutSticker(h2, w2, mark)) return true;
    Init(mark);

    if(TryPutSticker(h1, w1, mark) && TryPutSticker(w2, h2, mark)) return true;
    Init(mark);

    if(TryPutSticker(w1, h1, mark) && TryPutSticker(w2, h2, mark)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W >> N;
    for(int i = 0; i < N; i++) {
        int h,w; cin >> h >> w;
        arr[i] = {h, w};
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if (TryPutSticker(arr[i].first, arr[i].second, arr[j].first, arr[j].second)) {
                answer = max(answer, arr[i].first * arr[i].second + arr[j].first * arr[j].second);
            }
        }
    }

    cout << answer;

}