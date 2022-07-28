#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 최소값 리턴
int Try(vector<pair<int,int>> &v)
{
    int answer = 1000000;
    int R = max(v[0].first, max(v[1].first, v[2].first));
    int C = v[0].second + v[1].second + v[2].second;
    answer = min(answer, R*C);

    R = v[0].first + v[1].first + v[2].first;
    C = max(v[0].second, max(v[1].second, v[2].second));
    answer = min(answer, R*C);

    R = v[1].first < v[2].first ? v[0].first+v[2].first : v[0].first+v[1].first;
    C = v[0].second <= v[1].second+v[2].second ? v[1].second+v[2].second : v[0].second;
    answer = min(answer, R*C);

    R = v[0].first < v[2].first ? v[1].first+v[2].first : v[1].first+v[0].first;
    C = v[1].second <= v[0].second+v[2].second ? v[0].second+v[2].second : v[1].second;
    answer = min(answer, R*C);

    R = v[0].first < v[1].first ? v[2].first+v[1].first : v[2].first+v[0].first;
    C = v[2].second <= v[0].second+v[1].second ? v[0].second+v[1].second : v[2].second;
    answer = min(answer, R*C);

    return answer;
}

void Permutation(vector<pair<int,int>> &v, int &answer)
{
    do
    {
        answer = min(answer, Try(v));
    } while(next_permutation(v.begin(), v.end()));
}

void Rotate(pair<int,int> &p)
{
    int tmp = p.first;
    p.first = p.second;
    p.second = tmp;
}



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--)
    {
        vector<pair<int,int>> ori(3);
        vector<pair<int,int>> v(3);
        for(int i = 0; i < 3; i++)
        {
            int r, c; cin >> c >> r;
            ori[i] = {r,c};
        }
        sort(ori.begin(), ori.end());

        int answer = 10000000;

        v = ori;
        Permutation(v, answer);

        v = ori;
        Rotate(v[0]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[1]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[2]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[0]); Rotate(v[1]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[1]); Rotate(v[2]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[0]); Rotate(v[2]);
        Permutation(v, answer);

        v = ori;
        Rotate(v[0]); Rotate(v[1]); Rotate(v[2]);
        Permutation(v, answer);

        cout << answer << '\n';
    }


}