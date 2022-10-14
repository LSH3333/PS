import 'dart:io';

void main()
{
    var s = stdin.readLineSync();
    var v = s!.split(' ').map ((o) => int.parse(o));
    var h = v.elementAt(0);
    var m = v.elementAt(1);
    var cost = int.parse(stdin.readLineSync()!);

    m += cost;
    h += m ~/ 60;
    print("${h%24} ${m%60}");
}