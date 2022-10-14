import 'dart:io';
import 'dart:math';

void main()
{
    var str = stdin.readLineSync()!;
    var v1 = str.split(' ').map((o) => int.parse(o));
    int a = v1.elementAt(0), b = v1.elementAt(1), c = v1.elementAt(2);

    if(a + b + c >= 100) print("OK");
    else
    {
        int t = min(min(a, b), c);
        if(a == t) print("Soongsil");
        else if(b == t) print("Korea");
        else print("Hanyang");
    }
}