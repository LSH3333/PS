using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();
            
            int t = int.Parse(sr.ReadLine());
            while(t-- > 0)
            {
                string[] _s = sr.ReadLine().Split(' ');                
                int n = int.Parse(_s[0]);
                double[] v = new double[n+1];
                double avg = 0;
                for (int i = 1; i <= n; i++)
                {
                    v[i - 1] = Double.Parse(_s[i]);
                    avg += v[i - 1];
                }
                avg /= n;

                double over = 0;
                for (int i = 0; i < n; i++) if (v[i] > avg) over++;

                double answer = over / n;
                answer *= 100;
                answer = Math.Round(answer, 3);
                WriteLine("{0:0.000}%", answer);
                

            }

        }
    }
}
