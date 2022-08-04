import 'dart:io';

void main()
{
    String? input = stdin.readLineSync(); // return String
    // input은 nullable이므로 !로 null이 아님을 나타내 줘야 함
    var list = input!.split(' ');
    int A = int.parse(list[0]);
    int B = int.parse(list[1]);
    print(A-B);
}