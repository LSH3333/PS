import 'dart:io';

void main()
{
    var str = stdin.readLineSync();
    var v1 = str!.split(' ').map((o) => int.parse(o));
    int score = 0;
    v1.forEach((element) {score += element;});

    str = stdin.readLineSync();
    var v2 = str!.split(' ').map((o) => int.parse(o));
    int score2 = 0;
    v2.forEach((element) {score2 += element;});

    if(score < score2) score = score2;
    print(score);

}