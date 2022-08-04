import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int A = int.parse(input[0]);
    int B = int.parse(input[1]);
    print(A+B);
    print(A-B);
    print(A*B);
    print((A/B).floor());
    print(A%B);
}