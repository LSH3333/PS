#include <iostream>
#include <vector>
#include <string>
using namespace std;

int S;
string N;
int R, C;
char b[25][200];


void Horz1(vector<vector<char>> &number) {
    for(int c = 1; c < 1 + S; c++) {
        number[0][c] = '-';
    }
}

void Horz2(vector<vector<char>> &number) {
    for(int c = 1; c < 1 + S; c++) {
        number[1+S][c] = '-';
    }
}

void Horz3(vector<vector<char>> &number) {
    for(int c = 1; c < 1 + S; c++) {
        number[2+S+S][c] = '-';
    }
}

void Vert1(vector<vector<char>> &number) {
    for(int r = 1; r < 1+S; r++) {
        number[r][0] = '|';
    }
}

void Vert2(vector<vector<char>> &number) {
    for(int r = 1; r < 1+S; r++) {
        number[r][C-1] = '|';
    }
}

void Vert3(vector<vector<char>> &number) {
    for(int r = R-2; r > R-2-S; r--) {
        number[r][0] = '|';
    }
}

void Vert4(vector<vector<char>> &number) {
    for(int r = 1; r < 1+S; r++) {
        number[r+S+1][C-1] = '|';
    }
}

void One(vector<vector<char>> &number) {
    Vert2(number);
    Vert4(number);
}

void Two(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert2(number);
    Vert3(number);
}

void Three(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert2(number);
    Vert4(number);
}

void Four(vector<vector<char>> &number) {
    Vert1(number);
    Vert2(number);
    Horz2(number);
    Vert4(number);
}

void Five(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert1(number);
    Vert4(number);
}

void Six(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert1(number);
    Vert3(number);
    Vert4(number);
}

void Seven(vector<vector<char>> &number) {
    Horz1(number);
    Vert2(number);
    Vert4(number);
}

void Eight(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert1(number);
    Vert2(number);
    Vert3(number);
    Vert4(number);
}

void Nine(vector<vector<char>> &number) {
    Horz1(number);
    Horz2(number);
    Horz3(number);
    Vert1(number);
    Vert2(number);
    Vert4(number);
}

void Zero(vector<vector<char>> &number) {
    Horz1(number);
    Horz3(number);
    Vert1(number);
    Vert2(number);
    Vert3(number);
    Vert4(number);
}

vector<vector<char>> DrawNumber(char num) {
    vector<vector<char>> number(R, vector<char>(C, ' '));

    if(num == '0') {
        Zero(number);
    } else if (num == '1') {
        One(number);
    } else if (num == '2') {
        Two(number);
    }else if (num == '3') {
        Three(number);
    }else if (num == '4') {
        Four(number);
    }else if (num == '5') {
        Five(number);
    }else if (num == '6') {
        Six(number);
    }else if (num == '7') {
        Seven(number);
    }else if (num == '8') {
        Eight(number);
    }else if (num == '9') {
        Nine(number);
    }

    return number;
}

void Init() {
    for(int r = 0; r < 25; r++) {
        for(int c = 0; c < 200; c++) {
            b[r][c] = ' ';
        }
    }
}


int main() {
    Init();
    cin >> S >> N;

    R = 2 * S + 3;
    C = S + 2;

//    cout << R << ' ' << C << endl;

    vector<vector<vector<char>>> v;

    for(char c : N) {
        auto res = DrawNumber(c);
        v.push_back(res);
    }

    for(int i = 0; i < (int)v.size(); i++) {

        for(int r = 0; r < R; r++) {
            for(int c = i*C+i; c < i*C+i+C; c++) {
                b[r][c] = v[i][r][c-(i*C+i)];
            }
        }
    }

    // print
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C * v.size() + v.size()-1; c++) {
            cout << b[r][c];
        } cout << '\n';
    }
}