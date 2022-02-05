using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static int MAX = 1000001;
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
            FindPrimeNumbers();

            while(true)
            {
                int n = int.Parse(sr.ReadLine());
                if (n == 0) break;
                int a = -1;
                int b = -1;
                for (int i = 1; i < n; i += 2)
                {
                    if (primeNumber[i] != 0 && primeNumber[n - i] != 0)
                    {
                        a = i;
                        b = n - i;
                        break;
                    }
                }
                if (a == -1 && b == -1)
                    WriteLine("Goldbach's conjecture is wrong.");
                else
                    WriteLine(n + " = " + a + " + " + b);

            }
        }
    }
}
