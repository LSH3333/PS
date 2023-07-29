#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int,int>> res;

// ??? ?? rate ?? ???? ???? ?? ????? ??
int CalTotalPrice(const vector<int> &emoticons, const vector<int> &saleRate, int rate) {
    int totalPrice = 0;

    for(int i = 0; i < saleRate.size(); i++) {
        // ?? ??
        int sale = saleRate[i];
        // ?? ???? ???
        if(sale >= rate) {
            // ??? ??
            int salePrice = emoticons[i] / 100 * (100 - sale);
            totalPrice += salePrice;
        }
    }
    return totalPrice;
}

void Cal(const vector<int> &emoticons, const vector<int> &saleRate, const vector<vector<int>> &users) {
    int emoticonSaleTotal = 0, emoticonServiceTotal = 0;

    for(auto user : users) {
        int rate = user[0], price = user[1];
        // ?? ?? ?? ???? ???? ?? ??
        int totalPrice = CalTotalPrice(emoticons, saleRate, rate);
        // ?? ??? ?? ?? ?? ?? ??? ?? ??, ??? ??
        if(totalPrice >= price) {
            emoticonServiceTotal++;
        }
            // ???? ??
        else {
            emoticonSaleTotal += totalPrice;
        }
    }

    res.push_back({emoticonServiceTotal, emoticonSaleTotal});
}

void SetEmoticonSaleRate(int depth, const vector<int> &emoticons,
                         vector<int> &saleRate, const vector<vector<int>> &users) {
    if (depth == saleRate.size()) {
        Cal(emoticons, saleRate, users);
        return;
    }

    for(int sale = 10; sale <= 40; sale += 10) {
        if(saleRate[depth] > 0) continue;
        saleRate[depth] = sale;
        SetEmoticonSaleRate(depth + 1, emoticons, saleRate, users);
        saleRate[depth] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    vector<int> saleRate(emoticons.size());
    SetEmoticonSaleRate(0, emoticons, saleRate, users);

    sort(res.begin(), res.end());

    answer.push_back(res.back().first);
    answer.push_back(res.back().second);
    return answer;
}

int main() {
//    vector<vector<int>> users = {
//            {40, 10000}, {25, 10000}
//    };
//    vector<int> emoticons = {7000, 9000};

    vector<vector<int>> users = {
            {40, 2900},
            {23, 10000},
            {11, 5200},
            {5,  5900},
            {40, 3100},
            {27, 9200},
            {32, 6900}
    };
    vector<int> emoticons = {1300, 1500, 1600, 4900};

    solution(users, emoticons);
}