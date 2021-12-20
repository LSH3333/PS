using static System.Console;
using System;
using System.Collections;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            int E, S, M;
            string[] s_tmp = ReadLine().Split();
            E = int.Parse(s_tmp[0]); S = int.Parse(s_tmp[1]); M = int.Parse(s_tmp[2]);

            int cnt = 1;
            int e = 1, s = 1, m = 1;
            while(true)
            {
                if (e == E && s == S && m == M) break;
                cnt++;

                if (e < 15) e++;
                else e = 1;

                if (s < 28) s++;
                else s = 1;

                if (m < 19) m++;
                else m = 1;
            }
            Write(cnt);

        }
    }
}
