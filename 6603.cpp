#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    while(true) {
        int k;
        // 집합 S
        vector<int> v;
        // permutation을 위한 인덱스
        vector<int> idx;

        // input..
        cin >> k;
        // k가 0이면 프로그램 종료
        if(k == 0) return 0;
        for(int i = 0; i < k; i++) {
            int num;
            cin >> num;
            v.push_back(num);

            // permuation을 위한 인덱스 벡터를 셋팅한다
            // 6개를 뽑아야하므로, 6개의 1을 idx 벡터에 푸쉬
            // N = 7일때 , idx = {1, 1, 1, 1, 1, 1, 0}
            if(i < 6) {
                idx.push_back(1);
            }
            else { // 6개 이후에는 0을 삽입
                idx.push_back(0);
            }
        }

        // idx벡터를 permuation을 돌리면서
        // 해당 인덱스가 1이라면 집합 s[idx]를 출력한다.
        do {
            for(int i = 0; i < idx.size(); i++) {
                if(idx[i] == 1) cout << v[i] << ' ';
            }
            cout << '\n';
        } while(prev_permutation(idx.begin(), idx.end()));
        cout << '\n';
    }



}