#include <iostream>
#include <vector>
using namespace std;

int N, K;
int zero;

void Print(vector<pair<int,bool>> &v)
{
    for(auto x : v) cout << '(' << x.first << ',' << x.second << ')' << ' ';
    cout << endl;
}


// 1
void MoveBelt(vector<pair<int,bool>> &v)
{
    pair<int, bool> f = v.back();
    for(int i = (int)v.size()-1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0] = f;

    // 내리는 위치의 로봇
    v[N-1].second = false;
}

// 2
void MoveRobot(vector<pair<int,bool>> &v)
{
    // 뒤에있는 로봇일수록 먼저 올라간 로봇이다
    for(int i = 2*N-2; i >= 0; i--)
    {
        if(!v[i].second) continue;

        // 다음 위치에 아직 내구도 남았고 로봇이 없음 : 이동 가능
        if(v[i+1].first > 0 && !v[i+1].second)
        {
            v[i].second = false;
            v[i+1].second = true;
            v[i+1].first--;
            if(v[i+1].first == 0) zero++;

            // 다음 위치가 내리는 위치임
            if(i+1 == N-1)
            {
                v[i+1].second = false; // 로봇 내림
            }
        }
    }
}

// 3
void PutRobot(vector<pair<int,bool>> &v)
{
    if(v.front().first != 0)
    {
        v.front().second = true;
        v.front().first--;
        if(v.front().first == 0) zero++;
    }
}

void Func(vector<pair<int,bool>> &v)
{
    // 1
    MoveBelt(v);
    // 2
    MoveRobot(v);
    // 3
    PutRobot(v);
}



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    // 내구도, 로봇 여부
    vector<pair<int,bool>> v(N*2);


    int num;
    for(int i = 0; i < 2*N; i++)
    {
        cin >> num;
        v[i] = {num, false};
    }

    int stage = 0;
    while(zero < K)
    {
        stage++;
        Func(v);
    }

    cout << stage;
}