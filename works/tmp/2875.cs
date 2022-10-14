using System.Collections;
using System.Collections.Generic;
using static System.Console;
using System.Text;

namespace Project1
{
    public class Class1
    {        
        public static void Main(string[] args)
        {
            int N, M, K;
            string[] s = ReadLine().Split();
            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
            K = int.Parse(s[2]);

            int team = 0, n = 0, m = 0;
            while(true)
            {
                n += 2; m += 1;
                if ((N + M) - (n + m) < K) break;
                if (n > N || m > M) break;
                team++;
            }
            Write(team);
        }
    }
}
