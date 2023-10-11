#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int P, M;

bool cmp(const pair<int,string> &a, const pair<int,string> &b) {
    return a.second < b.second;
}

struct Room {
    // 0:waiting, 1:started
    int status;
    int minLevel, maxLevel;
    vector<pair<int,string>> players;
};

bool FindPossibleRoom(vector<Room> &rooms, int level, string &id) {
    for(auto &room : rooms) {
        if (room.minLevel <= level && level <= room.maxLevel &&
            room.players.size() < M && room.status == 0) {
            room.players.push_back({level, id});
            // ?? ?? ??
            if(room.players.size() == M) {
                room.status = 1;
            }
            return true;
        }
    }
    return false;
}

void CreateNewRoom(vector<Room> &rooms, int level, string id) {
    Room room{0, level-10, level+10, {{level, id}}};
    if(room.players.size() == M) {
        room.status = 1;
    }
    rooms.push_back(room);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<Room> rooms;
    cin >> P >> M;
    for(int i = 0; i < P; i++) {
        int level;
        string id;
        cin >> level >> id;

        // ?? ?? ? ?? ??? ?? ??
        if (!FindPossibleRoom(rooms, level, id)) {
            CreateNewRoom(rooms, level, id);
        }
    }



    for(auto &room : rooms) {
        if(room.status == 0) cout << "Waiting!\n";
        else cout << "Started!\n";

        sort(room.players.begin(), room.players.end(), cmp);
        for (const auto &x: room.players) {
            cout << x.first << ' ' << x.second << "\n";
        }
    }
}