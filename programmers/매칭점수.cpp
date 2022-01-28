#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <sstream>
#include <unordered_map>
using namespace std;

struct Page
{
    int idx;
    string name;
    int basicScore = 0;
    int linkToOthersNum = 0; // 해당 페이지에서 나가는 링크의 수
    vector<string> linkFromOthers; // 해당 페이지를 가르키는 링크들의 이름
    double linkScore = 0.0;
    double matchingScore = 0.0;
};

unordered_map<string, Page> map;

string FindName(string &page)
{
    string metaPattern = "<meta property=\"og:url\" content=\"";
    int urlStartIdx = page.find(metaPattern) + metaPattern.size();
    int urlEndIdx = page.find("\"", urlStartIdx);
    string urlName = page.substr(urlStartIdx, urlEndIdx-urlStartIdx);

    return urlName;
}

string ToLower(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

int CalBasicScore(string &page, string word)
{
    int cnt = 0;
    word = ToLower(word);
    string body;
    int bodyIdx = page.find("<body>");
    int bodyEndIdx = page.find("</body>");
    for(int i = bodyIdx; i < bodyEndIdx; i++) body.push_back(page[i]);
    body = ToLower(body);

    // 알파벳 제외한 모든 문자 공백으로 변경
    for(int i = 0; i < body.size(); i++)
    {
        if(body[i] >= 'a' && body[i] <= 'z') continue;
        body[i] = ' ';
    }

    stringstream ss(body);
    string token;
    while(ss >> token)
    {
        if(token == word) cnt++;
    }

    return cnt;
}

void FindLink(string &page, string curPageName)
{
    int idx = 0;
    while(true)
    {
        idx = page.find("<a", idx);
        if(idx == string::npos) break; // 더이상 a 태그를 찾을수 없음
        string linkTo;
        for(int i = idx+9; i < page.size(); i++)
        {
//            if(page[i] == '"') { idx = i; break; }
            if(page.substr(i, 2) == "\">") { idx = i; break; }
            linkTo.push_back(page[i]);
        }
        map[curPageName].linkToOthersNum++;
        // 해당 링크가 존재하는 페이지일때만
        if(map.find(linkTo) != map.end())
            map[linkTo].linkFromOthers.push_back(curPageName);
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;

    // 우선 map에 모든 페이지들과 인덱스 저장해놓는다
    for(int i = 0; i < pages.size(); i++)
    {
        Page pg;
        string name = FindName(pages[i]);
        pg.idx = i;
        pg.name = name;
        map[name] = pg;
    }

    for(auto page : pages)
    {
        string name = FindName(page);
        // 기본점수 계산
        // 해당 페이지의 외부링크의수, 가르키는 링크 찾음
        FindLink(page, name);
        map[name].basicScore = CalBasicScore(page, word);
    }

    // 링크점수 계산
    for(auto &x : map)
    {
        double sum = 0;
        for(auto linkFrom : x.second.linkFromOthers)
        {
            sum += (double)map[linkFrom].basicScore / (double)map[linkFrom].linkToOthersNum;
        }
        x.second.linkScore = sum;
    }

    // 매칭점수 계산
    for(auto &x : map)
    {
        x.second.matchingScore = (double)x.second.basicScore + x.second.linkScore;
    }
//
//    for(auto x : map)
//    {
//        cout << x.first << endl;
//        cout << "idx: " << x.second.idx << endl;
//        cout << x.second.basicScore << endl;
//        cout << x.second.linkToOthersNum << endl;
//        cout << "link점수: " <<  x.second.linkScore << endl;
//        cout << x.second.matchingScore << endl;
//        for(auto y : x.second.linkFromOthers) cout << y << ' '; cout << endl << endl;
//    }

    double maxScore = 0.0;
    int ansIdx = 0;
    for(auto x : map)
    {
        if(x.second.matchingScore > maxScore)
        {
            answer = x.second.idx;
            ansIdx = x.second.idx;
            maxScore = x.second.matchingScore;
        }
        else if(x.second.matchingScore == maxScore && x.second.idx < ansIdx)
        {
            answer = x.second.idx;
            ansIdx = x.second.idx;
            maxScore = x.second.matchingScore;
        }
    }

    return answer;
}

int main()
{
    string word = "blind";
    vector<string> pages =
            {
                {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
                 "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
                 "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"}
            };
    solution(word, pages);

//    string word = "Muzi";
//    vector<string> pages =
//            {
//                    "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
//            };
//    solution(word, pages);
}