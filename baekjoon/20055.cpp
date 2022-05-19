#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;

void MoveBelt(vector<pair<int,bool>> &v)
{
    pair<int, bool> f = v.back();

    for(int i = (int)v.size()-1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0] = f;
}

void Print(vector<pair<int,bool>> &v)
{
    for(auto x : v) cout << x.first << ' ';
    cout << endl;
}

// 2
void MoveRobot(vector<pair<int,bool>> &v, queue<int> &robots)
{
    


//    for(auto &robotIdx : robots)
//    {
//        // 로봇의 다음위치가 내리는 위치
//        if(robotIdx == N*2-2)
//        {
//
//        }
//        else
//        {
//            // 로봇 이동 가능
//            if(!v[robotIdx+1].second && v[robotIdx+1].first > 0)
//            {
//                robotIdx = robotIdx + 1;
//                v[robotIdx].first--;
//                v[robotIdx].second = true;
//            }
//        }
//    }
}

// 3
void PutRobot(vector<pair<int,bool>> &v, queue<int> &robots)
{
    if(v.front().first != 0)
    {
        v.front().second = true;
        robots.push(0);
    }
}

void Func(vector<pair<int,bool>> &v)
{
    // 1
    MoveBelt(v);

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    // 내구도, 로봇 여부
    vector<pair<int,bool>> v(N*2);
    // robot index
    queue<int> robots;

    int num;
    for(int i = 0; i < 2*N; i++)
    {
         cin >> num;
         v[i] = {num, false};
    }


}