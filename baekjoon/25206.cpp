#include <iostream>
using namespace std;

/**
 * A+	4.5
A0	4.0
B+	3.5
B0	3.0
C+	2.5
C0	2.0
D+	1.5
D0	1.0
F	0.0
 */

double GetGradeAvg(string grade) {
    if(grade == "A+") return 4.5;
    else if(grade == "A0") return 4.0;
    else if(grade == "B+") return 3.5;
    else if(grade == "B0") return 3.0;
    else if(grade == "C+") return 2.5;
    else if(grade == "C0") return 2.0;
    else if(grade == "D+") return 1.5;
    else if(grade == "D0") return 1.0;
    else return 0.0;
}

int main() {
    double sumOfScore = 0.0, sumOfScoreTimesAvg = 0.0;

    for(int i = 0; i < 20 ; i++) {
        string name, grade;
        double score;
        cin >> name >> score >> grade;
        if(grade == "P") continue;


        sumOfScoreTimesAvg += (score * GetGradeAvg(grade));
        sumOfScore += score;
    }

    cout << sumOfScoreTimesAvg / sumOfScore << endl;
}