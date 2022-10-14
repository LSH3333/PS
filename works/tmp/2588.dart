import 'dart:io';

void main()
{
    int A = int.parse(stdin.readLineSync()!);
    int B = int.parse(stdin.readLineSync()!);

    print(A * (B % 10));
    print(A * (B/10%10).floor());
    print(A * (B/100).floor());
    print(A*B);

}