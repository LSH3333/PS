#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// {genre, play, index}
bool cmp(const tuple<string,int,int> &a, const tuple<string,int,int> &b)
{
    // genre가 같으면 play 기준 내림차순 정렬
    if(get<0>(a) == get<0>(b))
    {
        // genre내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
        if(get<1>(a) == get<1>(b))
        {
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    // genre 기준 내림차순 정렬
    return get<0>(a) < get<0>(b);
}

bool cmp2(const pair<string,int> &a, const pair<string,int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int, greater<>> genres_m;
    // genre, {plays, idx}
    vector<tuple<string, int, int>> v;
    for(int i = 0; i < genres.size(); i++)
    {
        genres_m[genres[i]] += plays[i];
        v.push_back(make_tuple(genres[i], plays[i], i));
    }
    vector<pair<string,int>> mv(genres_m.begin(), genres_m.end());
    sort(mv.begin(), mv.end(), cmp2);
    sort(v.begin(), v.end(), cmp);

//    for(auto x : v) cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << endl;
//    cout << endl;
//    for(auto x : mv) cout << x.first << ' ' << x.second << endl;

    for(int i = 0; i < mv.size(); i++)
    {
        string targetGenre = mv[i].first;
        for(int j = 0; j < v.size(); j++)
        {
            if(get<0>(v[j]) == targetGenre)
            {
                answer.push_back(get<2>(v[j]));
                if(j < v.size()-1 && get<0>(v[j+1]) == targetGenre) answer.push_back(get<2>(v[j+1]));
                break;
            }
        }
    }

//    for(auto x : answer) cout << x << ' ';
    return answer;
}
