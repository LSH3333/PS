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

    for(int i = 0; i < n; i++)
        idx.push_back(i);

    do{
        // idx,marble 벡터 복사
        vector<int> idx_clone;
        for(int i = 0; i < n; i++)
            idx_clone.push_back(i);
        vector<int> marble_clone(marble);

        // 하나의 조합에 대한 계산
        int energy = 0;
        int in = 1;
        while(idx_clone.size() > 2)
        {
            /*
            for(auto x : idx_clone)
                cout << x << ' ';
            cout << endl;
            for(auto x : marble_clone)
                cout << x << ' ';
            cout << endl;
            */
            for(int i = 0; i < idx_clone.size(); i++)
            {
                if(idx_clone[i] == idx[in])
                {
                    //cout << "idx[in]: " << idx[in] << endl;
                    //cout << "energy: " <<marble_clone[i-1] * marble_clone[i+1] << endl;
                    energy += marble_clone[i-1] * marble_clone[i+1];
                    marble_clone.erase(marble_clone.begin()+i);
                    idx_clone.erase(idx_clone.begin()+i);
                    break;
                }
            }
            in++;
            //cout << endl;
        }
        //cout << "------------------- " << energy << endl;
        // energy 최댓값 갱신
        ans = max(ans, energy);
        //cout << endl;
    }while(next_permutation(idx.begin()+1, idx.end()-1));

    cout << ans;

}
