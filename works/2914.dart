import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int numOfSongs = int.parse(input[0]);
    int avg = int.parse(input[1]) - 1;
    int ans = avg * numOfSongs;
    print(ans+1);
}