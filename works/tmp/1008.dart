import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    double a = double.parse(input[0]);
    double b = double.parse(input[1]);
    print(a/b);
}