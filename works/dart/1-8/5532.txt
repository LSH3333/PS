import 'dart:io';

void main()
{
    int L = int.parse(stdin.readLineSync()!);
    int A = int.parse(stdin.readLineSync()!);
    int B = int.parse(stdin.readLineSync()!);
    int C = int.parse(stdin.readLineSync()!);
    int D = int.parse(stdin.readLineSync()!);

    int a = A % C == 0 ? A ~/ C : A ~/ C + 1;
    int b = B % D == 0 ? B ~/ D : B ~/ D + 1;
    int ans = a < b ? L - b : L - a;
    print(ans);
}