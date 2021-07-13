#include <iostream>
#include <string>

using namespace std;

int n, m;
char dna[1001][51];
// 사전순 정렬을 위해
char alp[4] = {'A', 'C', 'G', 'T'};
int alp_cnt[4] = {0,};
string ans = "";

// 만들어진 cnt_alp 배열을 이용해서 특정 열에서 어떤 알파벳이 가장 많이 사용되었는지 계산한다
// 가장 많이 사용된 알파벳을 char형으로 리턴한다
char MostUsedAlp()
{
    char c = alp[0];
    int max_cnt = alp_cnt[0]; // 4

    for(int i = 1; i < 4; i++)
    {
        if(max_cnt < alp_cnt[i])
        {
            max_cnt = alp_cnt[i];
            c = alp[i];
        }
    }

    return c;
}

void Init_alp_cnt()
{
    for(int i = 0; i < 4; i++)
    {
        alp_cnt[i] = 0;
    }
}

// 만들어진 Hamming Distance가 가장 작은 DNA를 입력받은 DNA들과 비교하며
// Hamming Distance의 합을 리턴한다
int CountHamming()
{
    int hamming = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dna[i][j] != ans[j])
            {
                hamming++;
            }
        }
    }
    return hamming;
}

int main()
{
    // inputs
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", dna[i]);
    }

    // 같은 열들끼리 알파벳을 비교한다
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 'A', 'C', 'G', 'T' 비교해서 해당하는
            // alp_cnt의 인덱스 값을 상승시킨다
            for(int a = 0; a < 4; a++)
            {
                if(dna[j][i] == alp[a])
                {
                    alp_cnt[a]++;
                }
            }
        }
        // 가장 많이 사용된 알파벳을 이어붙인다
        ans += MostUsedAlp();
        // 다음 열을 세기 위하여 alp_cnt 배열을 초기화한다
        Init_alp_cnt();
    }

    cout << ans << '\n' << CountHamming();
}