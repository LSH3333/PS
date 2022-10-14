using System;
using System.Collections.Generic;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        public static int A, P;

        public static int Cal(int n)
        {
            int sum = 0;
            while(n > 0)
            {
                sum += (int)(Math.Pow(n % 10, P));
                n /= 10;
            }
            return sum;
        }

        static void Main(string[] args)
        {
            String temp = ReadLine();
            String[] str_temp = temp.Split(' ');
            A = int.Parse(str_temp[0]);
            P = int.Parse(str_temp[1]);
            Dictionary<int, int> m = new Dictionary<int, int>();
            int cnt = 1;
            m[A] = cnt++;

            while(true)
            {
                A = Cal(A);
                if(m.ContainsKey(A))
                {
                    Write(m[A] - 1);
                    break;
                }
                m[A] = cnt++;
            }

        }

    }
}
