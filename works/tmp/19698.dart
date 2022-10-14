import 'dart:io';
import 'dart:math';

void main()
{
    var str = stdin.readLineSync()!;
    var v1 = str.split(' ').map((o) => int.parse(o));
    int N = v1.elementAt(0), W = v1.elementAt(1), H = v1.elementAt(2), L = v1.elementAt(3);

    int w = W ~/ L;
    int h = H ~/ L;
    int ans = w * h;
    print(ans < N ? ans : N);
}