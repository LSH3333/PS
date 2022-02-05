using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static int MAX = 123456 * 2 + 10;
        static int[] primeNumber = new int[MAX];

        static void FindPrimeNumbers()
        {
            for (int i = 2; i < MAX; i++)
                primeNumber[i] = i;

            for (int i = 2; i < Math.Sqrt(MAX); i++)
            {
                if (primeNumber[i] == 0) continue;
                for (int j = i * i; j < MAX; j += i)
                {
                    primeNumber[j] = 0;
                }
            }
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int n = -1;
            FindPrimeNumbers();
            while(true)
            {
                n = int.Parse(sr.ReadLine());
                if (n == 0) break;
                int cnt = 0;
                for (int i = n + 1; i <= 2 * n; i++)
                    if (primeNumber[i] != 0) cnt++;
                WriteLine(cnt);
            }
        }
    }
}
