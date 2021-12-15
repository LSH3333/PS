#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int arr[1010][1010];
    int dr[] = {1, 0, -1};
    int dc[] = {0, 1, -1};

    int r = 1, c = 1;
    int cnt = 1;
    int dir = 0;

    while(true)
    {
        arr[r][c] = cnt++;

        switch(dir)
        {
            case 0:
                if(r + dr[dir] > n || arr[r+dr[dir]][c] != 0) dir = 1;
                break;

            case 1:
                if(c + dc[dir] > n || arr[r][c+dc[dir]] != 0) dir = 2;
                break;

            case 2:
                if(arr[r+dr[dir]][c+dc[dir]] != 0) dir = 0;
                break;
        }

        r = r + dr[dir];
        c = c + dc[dir];

        if(cnt > n * (n + 1) / 2) break;
    }

//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++)
//        {
//            cout << arr[i][j] << ' ';
//        } cout << endl;
//    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(arr[i][j] == 0) continue;
            answer.push_back(arr[i][j]);
        }
    }
    

    return answer;
}