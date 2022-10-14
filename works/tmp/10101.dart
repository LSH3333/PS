import 'dart:io';

void main()
{
    var a = int.parse(stdin.readLineSync()!);
    var b = int.parse(stdin.readLineSync()!);
    var c = int.parse(stdin.readLineSync()!);

    if(a+b+c != 180) print("Error");
    else if(a != b && b != c && c != a) print("Scalene");
    else if((a==b && b!=c) || (b==c && a!=b) || (a==c && c!=b)) print("Isosceles");
    else if(a == 60 && b == 60 && c == 60) print("Equilateral");
}