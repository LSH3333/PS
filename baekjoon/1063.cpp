#include <iostream>
using namespace std;

string Next(const string &cur, const string &dir) {
    char col = cur[0], row = cur[1];
    if(dir == "R") {
        col = char(col + 1);
    }
    else if (dir == "L") {
        col = char(col - 1);
    }
    else if(dir == "B") {
        row = char(row - 1);
    }
    else if(dir == "T") {
        row = char(row + 1);
    }
    else if(dir == "RT") {
        row = char(row + 1);
        col = char(col + 1);
    }
    else if(dir == "LT") {
        row = char(row + 1);
        col = char(col - 1);
    }
    else if(dir == "RB") {
        row = char(row - 1);
        col = char(col + 1);
    }
    else if(dir == "LB") {
        row = char(row - 1);
        col = char(col - 1);
    }

    string ret;
    ret.push_back(col);
    ret.push_back(row);
    return ret;
}

bool MoveCheck(const string &cur, const string &dir) {
    string next = Next(cur, dir);
    char col = next[0];
    char row = next[1];

    // ?? ???
    if(row < '1' || row > '8' || col < 'A' || col > 'H') {
        return false;
    } else {
        return true;
    }
}

//void Move(string &cur, const string &dir) {
//    pair<char,char> next = Next(cur, dir);
//    cur[0] = next.first;
//    cur[1] = next.second;
//}

int main() {
    int N;
    string king, stone;
    cin >> king >> stone >> N;

    for(int i = 0; i < N; i++) {
        string dir; cin >> dir;

        // ? ?? ?? ??
        if(MoveCheck(king, dir)) {
            // ?? ?? ??
            string kingNext = Next(king, dir);
            // ?? ?? ??? ?? ??
            if(kingNext == stone) {
                // ?? ???? ??? ?? ??
                if(MoveCheck(stone, dir)) {
                    string stoneNext = Next(stone, dir);
                    king = kingNext;
                    stone = stoneNext;
                }
            }
                // ?? ?? ?? ??
            else {
                king = kingNext;
            }
        }
    }

    cout << king << '\n' << stone;
}