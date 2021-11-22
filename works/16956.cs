using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            String temp = ReadLine();
            String[] str_temp = temp.Split(' ');
            int R = int.Parse(str_temp[0]);
            int C = int.Parse(str_temp[1]);            
            string[] arr = new string[501];

            for(int i = 0; i < R; i++)
                arr[i] = ReadLine();

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (arr[i][j] != 'W') continue;
                    bool flag = false;

                    if (i - 1 >= 0)
                        if (arr[i - 1][j] == 'S') flag = true;
                    if (j + 1 < C)
                        if (arr[i][j + 1] == 'S') flag = true;
                    if (i + 1 < R)
                        if (arr[i + 1][j] == 'S') flag = true;
                    if (j - 1 >= 0)
                        if (arr[i][j - 1] == 'S') flag = true;

                    if(flag)
                    {
                        WriteLine(0);
                        return;
                    }
                }
            }

            WriteLine(1);
            
            for(int i = 0; i < R; i++)
            {
                string str = "";
                for (int j = 0; j < C; j++)
                {
                    if (arr[i][j] == '.') str += 'D';
                    else str += arr[i][j];
                }
                WriteLine(str);
            }
        }

    }
}
