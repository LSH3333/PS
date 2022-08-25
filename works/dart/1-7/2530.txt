import 'dart:io';

void main()
{
    var str = stdin.readLineSync();
    var v = str!.split(' ').map ((o) => int.parse(o));
    var h = v.elementAt(0);
    var m = v.elementAt(1);
    var s = v.elementAt(2);
    var cost = int.parse(stdin.readLineSync()!);

    s += cost;
    m += s ~/ 60;
    h += m ~/ 60;
    print("${h%24} ${m%60} ${s%60}");
}