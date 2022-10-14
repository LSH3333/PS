import 'dart:io';

void main()
{
    int A = int.parse(stdin.readLineSync()!);
    int B = int.parse(stdin.readLineSync()!);
    int C = int.parse(stdin.readLineSync()!);
    int D = int.parse(stdin.readLineSync()!);
    int P = int.parse(stdin.readLineSync()!);

    int X = A * P;
    int Y = P <= C ? B : B + D * (P - C);
    print(X < Y ? X : Y);

}