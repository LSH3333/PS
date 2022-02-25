using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static long dfs(long distance, long moved, long cnt)
        {
            if (distance == 0) return cnt;

            for (long move = moved + 1; move >= moved - 1; move--)
            {
                if (move <= 0) continue;
                long sum = (move * (move + 1)) / 2;
                if (sum <= distance)
                {
                    return dfs(distance - move, move, cnt + 1);
                }
            }
            return 0;
        }


        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int t = int.Parse(sr.ReadLine());
            string[] _s;
            while(t-- > 0)
            {
                _s = sr.ReadLine().Split();
                long x = int.Parse(_s[0]);
                long y = int.Parse(_s[1]);
                long distance = y - x;
                long ans = dfs(distance, 0, 0);
                WriteLine(ans);
            }

        }
    }
}
