using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static int GetPos(int n)
        {
            int len = 1;
            int val = n;
            int cnt = 0;
            int num = 1;

            while (val > 0)
            {
                if (val / 10 == 0)
                {
                    cnt += (n - len + 1) * num;
                    break;
                }
                else
                {
                    cnt += 9 * len * num;
                    len *= 10;
                    num++;
                    val /= 10;
                }
            }
            // 자릿수
            return cnt;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            int n = int.Parse(_s[0]);
            int k = int.Parse(_s[1]);
            if(n == 9 && k == 9) {Write(9); return;}
            int nPos = GetPos(n);
            if(k > nPos) { Write(-1); return; }

            int cnt = 0;
            long num1 = 9, num2 = 1, res = 0;
            while (true)
            {
                if (res + num1 * num2 > k) break;
                res += num1 * num2;
                num1 *= 10;
                num2++;
                cnt++;
            }
            cnt++;

            double pos_d = 0;
            if (cnt == 0) pos_d = 1;
            else pos_d = Math.Pow(10, cnt - 1);

            int pos = (int)pos_d;
            res++;
            int num = pos;
            while (true)
            {
                if (res > k) break;
                num++;
                res += cnt;
            }

            num--; res -= cnt;
            string num_s = num.ToString();
            char answer = num_s[k - (int)res];
            WriteLine(answer);
        }

    }
}
