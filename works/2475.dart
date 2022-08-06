import 'dart:io';

void main()
{
    var input = stdin.readLineSync()!.split(' ');
    int ans = 0;
    for(int i = 0; i < input.length; i++) {
        ans += int.parse(input[i]) * int.parse(input[i]);
    }
    print(ans%10);
}