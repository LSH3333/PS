import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int n = int.parse(input[0]);
    print((n * (n+1) / 2).floor());
}