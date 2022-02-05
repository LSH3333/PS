using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());           
            int n = int.Parse(sr.ReadLine());
            int num = 1;
            int cnt = 0;

            while(num <= n)
            {
                cnt += (n - num + 1);
                num *= 10;
            }
            Write(cnt);           
        }
    }
}
