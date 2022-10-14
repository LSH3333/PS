import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int R1 = int.parse(input[0]);
    int S = int.parse(input[1]);
    print((S*2)-R1);

}