using static System.Console;
using System;
using System.Collections;
using System.Text;
using System.IO;
using System.Collections.Generic;

namespace Project1
{
    public class Class1
    {
       
        public static void Main(string[] args)
        {
            string[] s = ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);

            if(N <= 1)
            {
                Write(1);
                return;
            }
            if(N <= 2)
            {
                if (M >= 9) Write(4);
                else Write((M - 1) / 2 + 1);
                return;
            }

            if(M < 5)
            {
                Write(M);
                return;
            }
            if(M <= 5)
            {
                Write(M - 1);
                return;
            }

            if(M > 5)
            {
                Write(M - 2);
            }
        }
    }
}
