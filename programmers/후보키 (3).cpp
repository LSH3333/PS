#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> used;
int answer;

// 최소성 검사
bool CheckMinimality(const vector<int> &comb)
{
    string str;
    for(auto x : comb) str += to_string(x);
    
    for(auto x : used)
    {
        int cnt = 0;
        for(auto y : x)
        {
            if(str.find(y) != string::npos) cnt++;
        }
        if(x.size() == cnt) return false;
    }
    
    return true;
}

// 유일성 검사
bool CheckUniqueness(const vector<int> &comb, const vector<vector<string>> &relation)
{
    vector<string> v;

    for(int i = 0; i < relation.size(); i++)
    {
        string str;
        for(auto j : comb)
        {
            str += relation[i][j];
        }
        v.push_back(str);
    }

    int size = v.size();
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if(size == v.size()) return true;
    else return false;
}

void MakeComb(int idx, int depth, int n, vector<bool> &mark, vector<int> &comb, const vector<vector<string>> &relation)
{
    if(depth == n)
    {
//        for(auto x : comb) cout << x << ' '; cout << endl;
        if(CheckMinimality(comb) && CheckUniqueness(comb, relation))
        {
//            cout << "comb: " ;
//            for(auto x : comb) cout << x << ' '; cout << endl;
            answer++;
            string str;
            for(auto x : comb) str += to_string(x);
            used.push_back(str);
        }

        return;
    }

    for(int i = idx; i < relation.front().size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        comb.push_back(i);
        MakeComb(i, depth+1, n, mark, comb, relation);
        mark[i] = false;
        comb.pop_back();
    }
}

int solution(vector<vector<string>> relation)
{

    for(int i = 1; i <= relation.front().size(); i++)
    {
        vector<bool> mark(relation.front().size()+1, false);
        vector<int> comb;
        MakeComb(0, 0, i, mark, comb, relation);
    }

//    cout << answer;
    return answer;
}

int main()
{
    vector<vector<string>> relation =
            {
                {"100","ryan","music","2"},
                {"200","apeach","math","2"},
                {"300","tube","computer","3"},
                {"400","con","computer","4"},
                {"500","muzi","music","3"},
                {"600","apeach","music","2"}
            };
    solution(relation);

    string s = "abc";

}