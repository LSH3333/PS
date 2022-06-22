#include <iostream>
#include <vector>
using namespace std;

int board[710][710];
int M, N;

void Cal(int idx, const pair<int,int> &curPair, vector<pair<int,int>> &v)
{
    if(idx < 1) return;
    if(v[idx].second == 0) return;
//    cout << "IDX: " << idx << endl;
    pair<int,int> oldPair = v[idx];
    pair<int,int> newPair = {oldPair.first + curPair.first, min(oldPair.second, curPair.second)};
    // 새로운 pair로 교체
    v[idx] = newPair;
//    cout << oldPair.first << ',' << oldPair.second << ' ' << curPair.first << ',' << curPair.second << ' ' << newPair.first << ',' << newPair.second << endl;
    int newIdx = idx - newPair.second;
    int x = oldPair.second > curPair.second ? oldPair.first : curPair.first;
    int y = abs(oldPair.second - curPair.second);

    Cal(newIdx, {x,y}, v);
}

void WriteFirstLine(const vector<int> &growth)
{
    // 첫행,열 보드에 입력
    int r = M-1, c = 0;
    for(int i = 1; i <= 2*M-1; i++)
    {
        int num = growth[i]+1;
        board[r][c] = num;
        if(r > 0) r--;
        else c++;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;

    vector<pair<int,int>> v(2*M, {0,0});
    for(int day = 0; day < N; day++)
    {
        int zero, one, two; cin >> zero >> one >> two;

        int zeroIdx = 0 + zero;
        if(zero != 0)
        {
            if(v[zeroIdx].second == 0) v[zeroIdx] = {0, zero};
            else
            {
                Cal(zeroIdx, {0,zero}, v);
            }
        }

        int oneIdx = zeroIdx+one;
        if(one != 0)
        {
            if(v[oneIdx].second == 0) v[oneIdx] = {1, one};
            else
            {
                Cal(oneIdx, {1,one}, v);
            }
        }


        int twoIdx = oneIdx+two;
        if(two != 0)
        {
            if(v[twoIdx].second == 0) v[twoIdx] = {2, two };
            else
            {
                Cal(twoIdx, {2,two}, v);
            }
        }


//        cout << zeroIdx << ' ' << oneIdx << ' ' << twoIdx << endl;
    }


    // 최종 첫행과 열의 성장값
    vector<int> growth(2*M);
    for(int i = 2*M-1; i >= 1; i--)
    {
        int num = v[i].first , cnt = v[i].second;
        for(int j = i; j > i-cnt; j--)
        {
            growth[j] = num;
        }
    }

//    for(int i = 1; i <= 2*M-1; i++) cout << growth[i] << ' '; cout<<endl;

    WriteFirstLine(growth);

    // 나머지 부분들
    int _r = 1, _c = 1;
    while(_r != M)
    {
        int r = _r, c = _c;
        while(c < M)
        {
            board[r][c] = max(max(board[r-1][c], board[r][c-1]), board[r-1][c-1]);
            c++;
        }
        c = _c;
        r++;
        while(r < M)
        {
            board[r][c] = max(max(board[r-1][c], board[r][c-1]), board[r-1][c-1]);
            r++;
        }

        _r++; _c++;
    }


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        } cout << '\n';
    }
}