using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            int left_x1 = int.Parse(_s[0]);
            int left_y1 = int.Parse(_s[1]);
            int right_x1 = int.Parse(_s[2]);
            int right_y1 = int.Parse(_s[3]);
            _s = sr.ReadLine().Split(' ');
            int left_x2 = int.Parse(_s[0]);
            int left_y2 = int.Parse(_s[1]);
            int right_x2 = int.Parse(_s[2]);
            int right_y2 = int.Parse(_s[3]);

            if (left_x1 > left_x2)
            {
                int temp_left_x = left_x2;
                int temp_left_y = left_y2;
                int temp_right_x = right_x2;
                int temp_right_y = right_y2;

                left_x2 = left_x1;
                left_y2 = left_y1;
                right_x2 = right_x1;
                right_y2 = right_y1;

                left_x1 = temp_left_x;
                left_y1 = temp_left_y;
                right_x1 = temp_right_x;
                right_y1 = temp_right_y;
            }

            string answer;
            if (right_x1 == left_x2)
            {
                if (right_y1 == left_y2 || left_y1 == right_y2) answer = "POINT";
                else if (left_y2 > right_y1) answer = "NULL";
                else if (left_y1 > right_y2) answer = "NULL";
                else answer = "LINE";
            }
            else if (right_x1 > left_x2)
            {
                if (right_y1 == left_y2) answer = "LINE";
                else if (left_y1 == right_y2) answer = "LINE";
                else if (right_y1 < left_y2) answer = "NULL";
                else if (left_y1 > right_y2) answer = "NULL";
                else answer = "FACE";
            }
            else
                answer = "NULL";

            WriteLine(answer);
        }

    }
}
