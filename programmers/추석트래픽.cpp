#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> v_begin, v_end;

// ms 단위로
void CalculateBeginTime(string endTime, string duration)
{
    stringstream ss(endTime);
    string h, m, s;
    getline(ss, h, ':');
    getline(ss, m, ':');
    getline(ss, s);

    int dh = (stoi(h) * 1000 * 60 * 60);
    int dm = stoi(m) * 1000 * 60;
    double d_s = stod(s) * 1000;
    int ds = (int)d_s;

    int i_endTime = dh + dm + ds;

    double tmp = stod(duration) * 1000;
    int dur = (int)tmp;
    int i_beginTime = i_endTime - dur + 1;

    v_begin.push_back(i_beginTime);
    v_end.push_back(i_endTime);
}


int solution(vector<string> lines) {
    int answer = 0;

    for(int i = 0; i < lines.size(); i++)
    {
        stringstream ss(lines[i]);
        string token;
        string endTime, duration;
        int cnt = 0;
        while(ss >> token)
        {
            switch(cnt++)
            {
                case 1:
                    endTime = token;
                    break;
                case 2:
                    duration = token;
                    break;
            }
        }
        CalculateBeginTime(endTime, duration);
    }


    for(int i = 0; i < v_begin.size(); i++)
    {
        int cnt = 0;
        // start time
        int x = v_begin[i];
        // start time + 1s
        int y = x + 1000 - 1;

        for(int j = 0; j < v_begin.size(); j++)
        {
            if(v_end[j] < x || v_begin[j] > y) continue;
            cnt++;
        }
        answer = max(answer, cnt);
    }

    for(int i = 0; i < v_end.size(); i++)
    {
        int cnt = 0;
        int x = v_end[i];
        int y = x + 1000 - 1;
//        cout << "x: " << x << ' ' << "y: " << y << endl;
        for(int j = 0; j < v_end.size(); j++)
        {
            if(v_end[j] < x || v_begin[j] > y) continue;
            cnt++;
        }

        answer = max(answer, cnt);
    }

    return answer;
}
