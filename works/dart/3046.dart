import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int A = int.parse(input[0]);
    int B = int.parse(input[1]);
    print((B*2)-A);
}