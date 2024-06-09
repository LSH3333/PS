#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char board[21][21];

void FindRowWords(vector<string> &words) {
    string word;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if (board[r][c] == '#') {
                if (word.size() >= 2) {
                    words.push_back(word);
                }
                word.clear();
            }
            else {
                word.push_back(board[r][c]);
            }
        }
        if (word.size() >= 2) {
            words.push_back(word);
        }
        word.clear();
    }
}

void FindColWords(vector<string> &words) {
    string word;
    for(int c = 0; c < C; c++) {
        for(int r = 0; r < R; r++) {
            if (board[r][c] == '#') {
                if (word.size() >= 2) {
                    words.push_back(word);
                }
                word.clear();
            }
            else {
                word.push_back(board[r][c]);
            }
        }
        if (word.size() >= 2) {
            words.push_back(word);
        }
        word.clear();
    }
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    vector<string> words;
    FindRowWords(words);
    FindColWords(words);


    sort(words.begin(), words.end());

    cout << words.front();
}