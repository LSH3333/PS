#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, vector<int>> m;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    // info
    for(int i = 0; i < info.size(); i++) {
        // "-"로 채워진 4x2
        vector<vector<string>> v(4, vector<string>(2, "-"));
        stringstream ss;
        ss.str(info[i]);

        string str = "";
        int score = 0;
        int idx = 0;
        while (ss >> str) {
            if (idx < 4)
                v[idx++][0] = str;
            else
                score = stoi(str);
        }

//        for(int j = 0; j < 4; j++)
//        {
//            for(int k = 0; k < 2; k++)
//            {
//                cout << v[j][k] << ' ';
//            }cout << endl;
//        } cout << endl;

        // 조합만들기
        for (int a = 0; a < 2; a++) {
            string t1, t2, t3, t4;
            t1 = v[0][a];
            for (int b = 0; b < 2; b++) {
                t2 = v[1][b];
                for (int c = 0; c < 2; c++) {
                    t3 = v[2][c];
                    for (int d = 0; d < 2; d++) {
                        t4 = v[3][d];
                        m[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }
    // score 오름차순 정렬
    for(auto it = m.begin(); it != m.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }

    // query
    for(int i = 0; i < query.size(); i++)
    {
        stringstream ss;
        ss.str(query[i]);

        string str = "";
        string s;
        int score = 0;
        int idx = 0;
        while(ss >> s)
        {
            if(s == "and") continue;

            if(idx++ < 4)
                str += s;
            else
                score = stoi(s);
        }

        //cout << "str: " << str << endl;
        auto lowerIt = lower_bound(m[str].begin(), m[str].end(), score);
        answer.push_back(m[str].size() - (lowerIt - m[str].begin()));
    }


    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);
}