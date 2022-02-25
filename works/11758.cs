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
            string[] _s = sr.ReadLine().Split();
            int x1 = int.Parse(_s[0]); int y1 = int.Parse(_s[1]);
            _s = sr.ReadLine().Split();
            int x2 = int.Parse(_s[0]); int y2 = int.Parse(_s[1]);
            _s = sr.ReadLine().Split();
            int x3 = int.Parse(_s[0]); int y3 = int.Parse(_s[1]);

            int a = x1 * y2 + x2 * y3 + x3 * y1;
            int b = x2 * y1 + x3 * y2 + x1 * y3;
            int cal = a - b;

            if (cal == 0) Write(0);
            else if (cal > 0) Write(1);
            else Write(-1);
        }
    }
}
