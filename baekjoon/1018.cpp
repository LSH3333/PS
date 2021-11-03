#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
char map[51][51];

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        scanf("%s", &map[i]);
    }

    int Min = 999;
    for(int i = 0; i < N-7; i++) {
        for(int j = 0; j < M-7; j++) {
            int cntB = 0; // 첫칸 B
            int cntW = 0; // 첫칸 W

            for(int a = i; a < i+8; a++) {
                for(int b = j; b < j+8; b++) {
                    // 첫칸 W 기준
                    if((a+b) % 2 == 0) {
                        if(map[a][b] == 'B') // B라면
                        {
                            cntW++;
                        }

                    }
                    else {
                        if(map[a][b] == 'W')
                        {
                            cntW++;
                        }
                    }
                    // 첫칸 B 기준
                    if((a+b) % 2 == 0) {
                        if(map[a][b] == 'W')
                            cntB++;
                    }
                    else {
                        if(map[a][b] == 'B')
                            cntB++;
                    }

                }
            }
            Min = min(Min, cntB);
            Min = min(Min, cntW);
        }
    }
    cout << Min;
}