import 'dart:io';

void main()
{
    var n = stdin.readLineSync();
    var v = stdin.readLineSync()!.split(' ');

    int cnt = 0;
    if(n == v[0]) cnt++;
    if(n == v[1]) cnt++;
    if(n == v[2]) cnt++;
    if(n == v[3]) cnt++;
    if(n == v[4]) cnt++;
    print(cnt);
}