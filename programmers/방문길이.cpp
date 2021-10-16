#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    //map<pair<int,int>, pair<int,int>> m;
    map<pair<pair<int,int>,pair<int,int>>, bool> m;
    int x = 0, y = 0;
    for(int i = 0; i < dirs.size(); i++)
    {
        int dir;
        switch(dirs[i])
        {
            case 'U':
                dir = 0;
                break;
            case 'R':
                dir = 1;
                break;
            case 'D':
                dir = 2;
                break;
            case 'L':
                dir = 3;
                break;
        }
        if((x + dx[dir] > 5) || (x + dx[dir] < -5) || (y + dy[dir] > 5) || (y + dy[dir] < -5)) continue;
        int prev_x = x, prev_y = y;
        x = x + dx[dir];
        y = y + dy[dir];

        // 이미 지나온길
        if(m[{{prev_x,prev_y},{x,y}}] || m[{{x,y},{prev_x,prev_y}}]) continue;
        //cout << x << ' ' << y << endl;
        m[{{prev_x,prev_y},{x,y}}] = true;
        answer++;
    }

    return answer;
}