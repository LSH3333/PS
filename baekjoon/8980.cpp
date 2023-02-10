#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, M;
int boxNum[2010];
int answer;

struct Data {
    int begin;
    int end;
    int box;
};

bool cmp(const Data &a, const Data &b) {
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C >> M;
    vector<Data> v(M);
    for(int i = 0; i < M; i++) {
        int begin, end, box;
        cin >> begin >> end >> box;
        v[i] = {begin, end, box};
    }
    sort(v.begin(), v.end(), cmp);


    for(auto x : v) {
        int maxBox = 0;
        for(int i = x.begin; i < x.end; i++) {
            maxBox = max(maxBox, boxNum[i]);
        }

        if(maxBox < C) {
            // 넣을수 있는 박스의 수
            int emptySpace = C - maxBox;
            // 넣을 박스의 수
            int putBox = 0;
            if(x.box <= emptySpace) {
                putBox = x.box;
            }
            else {
                putBox = emptySpace;
            }
            answer += putBox;
            for(int i = x.begin; i < x.end; i++) boxNum[i] += putBox;
        }
    }

    cout << answer;
}