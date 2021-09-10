#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int rowSize, colSize;
vector<string> superkey; // 유일성 만족하는 부분집합

bool Check(vector<vector<string>> relation, vector<int> colIdx)
{
    if(colIdx.empty()) return false;
    vector<string> v;

    for(int r = 0; r < rowSize; r++)
    {
        string temp = "";
        for(int i = 0; i < colIdx.size(); i++)
        {
            temp += relation[r][colIdx[i]];
        }
        v.push_back(temp);
    }

    for(int i = 0; i < v.size(); i++)
    {
        string flag = v[i];
        for(int j = 0; j < v.size(); j++)
        {
            if(i == j) continue;
            if(flag == v[j]) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    rowSize = relation.size();
    colSize = relation[0].size();


    for(int cnt = 1; cnt <= colSize; cnt++)
    {
        bool mark[10] = {false, };
        for(int i = 0; i < cnt; i++) mark[i] = true;

        // 모든 부분 집합 구함 (조합)
        do {
            vector<int> colIdx;
            for(int i = 0; i < colSize; i++)
            {
                if(mark[i]) colIdx.push_back(i);
            }

            // 해당 부분집합이 유일성 만족하는지 확인
            if(Check(relation, colIdx))
            {
                string temp = "";
                for(int i = 0; i < colIdx.size(); i++)
                    temp += to_string(colIdx[i]);

                superkey.push_back(temp);
            }

        }while(prev_permutation(mark, mark+colSize));
    }

    // 유일성 만족하는 superkey들 포함관계를 조사
    for(int i = superkey.size()-1; i >= 0; i--)
    {
        string flag = superkey[i];
        bool contain = false;
        for(int j = 0; j < i; j++)
        {
            int same = 0;
            string target = superkey[j];
            for(int a = 0; a < target.size(); a++)
            {
                for(int b = 0; b < flag.size(); b++)
                {
                    if(target[a] == flag[b]) {same++; break;}
                }
            }
            // target이 flag에 포함됨
            if(same == target.size()) {contain=true; break;}
        }
        if(!contain) answer++;
    }

    return answer;
}

int main()
{
//    vector<vector<string>> relation =
//            {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},
//                {"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
//    solution(relation);

    vector<vector<string>> relation = {{"100","ryan","music","2"}};
    solution(relation);
}