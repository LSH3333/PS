#include <iostream>
#include <vector>
using namespace std;

#define INF 50000
int depth[40010];
int answer[40010];
int holes[3000];
int N;
int W;
int K;

void Input()
{
    cin >> N;
    int idx = 0;
    int zero1,zero2; cin >> zero1 >> zero2;
    for(int i = 0; i < N/2-1; i++)
    {
        int r1, c1, r2 ,c2;
        cin >> c1 >> r1 >> c2 >> r2;
        int w = c2-c1;
        for(int j = 0; j < w; j++)
        {
            depth[idx++] = r1;
        }
    }
    int w1, w2; cin >> w1 >> w2;
    W = w1;

    // holes
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        holes[i] = a;
    }

    for(int i = 0; i < W; i++)
    {
        answer[i] = INF;
    }
}

void CheckDepth(int &target, int i)
{
    if(depth[target] <= depth[i]) answer[i] = min(answer[i], depth[i]-depth[target]);
    else {answer[i] = 0; target = i;}
}

void Check(int holeIdx)
{
    int target = holeIdx;
    // left
    answer[target] = 0;
    for(int i = holeIdx-1; i >= 0; i--)
    {
        CheckDepth(target, i);
    }
    // right
    target = holeIdx;
    for(int i = holeIdx+1; i < W; i++)
    {
        CheckDepth(target, i);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    Input();

    for(int i = 0; i < K; i++)
    {
        int holeIdx = holes[i];
        Check(holeIdx);
    }

    int sum = 0;
    for(int i = 0; i < W; i++) sum += answer[i];
    cout << sum;

}