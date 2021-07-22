#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 0;

vector<int> marble;
vector<int> idx;

int main()
{
    // inputs
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        marble.push_back(w);
    }

    // {0,1,2,...,n-1}
    for(int i = 0; i < n; i++)
        idx.push_back(i);

    do {
        // idx, marble 벡터 복사해서 사용
        vector<int> idx_clone;
        for(int i = 0; i < n; i++)
            idx_clone.push_back(i);
        vector<int> marble_clone(marble);

        // 하나의 조합에 대한 계산
        int energy = 0;
        // idx 배열에는 조합이 저장되어 있다
        // {1,2,3}, {1,3,2} ... 이런식으로 permutation 함수에 의해 조합이 만들어진다
        // idx[in]의 in값을 증가시키면서 {1,2,3} 조합의 경우 1번구슬->2번구슬->3번구슬 순으로 뽑는다
        // {1,3,2} 조합의 경우 1번구슬->3번구슬->2번구슬 순으로 뽑는다
        int in = 1;
        // 에너지를 계산하고 구슬을 제거할것이므로, idx_clone의 사이즈는 계속 줄어든다
        while(idx_clone.size() > 2)
        {
            for(int i = 0; i < idx_clone.size(); i++)
            {
                if(idx_clone[i] == idx[in])
                {
                    // 고른 에너지 구슬의 양쪽 구슬의 에너지를 합한다
                    energy += marble_clone[i-1] * marble_clone[i+1];
                    // 고른 구슬을 제거한다
                    marble_clone.erase(marble_clone.begin()+i);
                    idx_clone.erase(idx_clone.begin()+i);
                    break;
                }
            }
            in++; // 다음으로 제거할 구슬로
        }
        // 이번 구슬을 뽑는 조합으로 만들어진 에너지와 최댓값을 갱신한다
        ans = max(ans, energy);
    } while(next_permutation(idx.begin()+1, idx.end()-1));

    cout << ans;
}