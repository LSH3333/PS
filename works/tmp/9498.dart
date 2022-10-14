import 'dart:io';

void main()
{
    int s = int.parse(stdin.readLineSync()!);
    if(s >= 90) print('A');
    else if(s >= 80) print('B');
    else if(s >= 70) print('C');
    else if(s >= 60) print('D');
    else print('F');



}