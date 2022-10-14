3 3 6import 'dart:io';
import 'dart:math';

void main()
{
    var s = stdin.readLineSync();
    var v = s!.split(' ').map((o) => int.parse(o));
    var a = v.elementAt(0), b = v.elementAt(1), c = v.elementAt(2);

    var res = 0;
    if(a == b && b == c)
        res = 10000 + a * 1000;
    else if(a == b && b != c)
        res = 1000 + a * 100;
    else if(b == c && c != a)
        res = 1000 + b * 100;
    else if(a == c && b != a)
        res = 1000 + a * 100;
    else
        res = max(max(a,b), c) * 100;

    print(res);
}