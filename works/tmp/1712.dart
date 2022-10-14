import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int A = int.parse(input[0]);
    int B = int.parse(input[1]);
    int C = int.parse(input[2]);
    int benefit = C - B;
    if(benefit <= 0) print(-1);
    else print((A / benefit).floor() + 1);


}