#include <string>
#include <vector>
#include <iostream>

using namespace std;

// time ? ??? ????
int CalAns(const vector<int> &cores, int time, int workLeft) {
    for(int i = 0; i < cores.size(); i++) {
        int core = cores[i];

        if((time-1) % core == 0) {
            workLeft--;
        }

        if(workLeft == 0) {
            return i+1;
        }
    }
    return 0;
}

// time ? ???? ?? ?
int Count(int time, const vector<int> &cores) {
    int done = 0;
    for(auto core : cores) {
        if(time % core == 0) {
            done += time / core;
        } else {
            done += (time / core) + 1;
        }
    }

    return done;
}

int solution(int n, vector<int> cores) {
    int answer = 0;
    int beforeTime = 0;

    int left = 1, right = 50000, mid = (left + right) / 2;
    int workDoneCnt = 0, workDoneMid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        // ???? ?? ??
        int done = Count(mid, cores);

        if(done < n) {
            left = mid + 1;
            beforeTime = mid;

            workDoneCnt = done;
            workDoneMid = mid;
        }
        else {
            right = mid - 1;
        }
    }

//    cout << "workDoneMid+1: " << workDoneMid+1 << ' ' << "workDoneCnt: " << workDoneCnt << endl;
    answer = CalAns(cores, workDoneMid+1, n - workDoneCnt);

    return answer;
}

int main() {
    int n = 6;
    vector<int> cores = {1,2,3};
    cout << solution(n, cores);
}