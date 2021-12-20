using static System.Console;
using System;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            int A, B, C, X, Y;
            string[] s = ReadLine().Split();
            A = int.Parse(s[0]);
            B = int.Parse(s[1]);
            C = int.Parse(s[2]);
            X = int.Parse(s[3]);
            Y = int.Parse(s[4]);

            int cost = 0;
            while (true)
            {
                int x = 1, y = 1;
                if (X <= 0) x = 0;
                if (Y <= 0) y = 0;

                int a = cost + A * x + B * y;
                int b = cost + C * 2;
                cost = Math.Min(a, b);

                X--; Y--;
                if (X < 0 && Y < 0) break;
            }
            Write(cost);
        }
    }
}
