using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{

    public class Class1
    {
        static int[] limit = new int[3];
        static int[] bottle = new int[3];
        static bool[,,] mark = new bool[210, 210, 210];
        static ArrayList answer = new ArrayList();

        public static void dfs()
        {
            if (bottle[0] == 0) answer.Add(bottle[2]);

            for (int i = 0; i < 3; i++)
            {
                if (bottle[i] == 0) continue;

                for (int j = 0; j < 3; j++)
                {
                    if (i == j) continue;
                    if (bottle[j] == limit[j]) continue;
                    int toPour = limit[j] - bottle[j];
                    int i_before = bottle[i], j_before = bottle[j];

                    if (bottle[i] - toPour >= 0)
                    {
                        bottle[i] -= toPour;
                        bottle[j] += toPour;
                    }
                    else
                    {
                        bottle[j] = bottle[i] + bottle[j];
                        bottle[i] = 0;
                    }
                    if (mark[bottle[0], bottle[1], bottle[2]])
                    {
                        bottle[i] = i_before;
                        bottle[j] = j_before;
                        continue;
                    }
                    mark[bottle[0], bottle[1], bottle[2]] = true;
                    dfs();
                    mark[bottle[0], bottle[1], bottle[2]] = false;
                    bottle[i] = i_before;
                    bottle[j] = j_before;
                }
            }
        }
       
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            int A = int.Parse(_s[0]);
            int B = int.Parse(_s[1]);
            int C = int.Parse(_s[2]);
            limit[0] = A; limit[1] = B; limit[2] = C;
            bottle[0] = 0; bottle[1] = 0; bottle[2] = C;
            mark[0, 0, C] = true;

            dfs();

            answer.Sort();
            ArrayList new_answer = new ArrayList();
            foreach(var x in answer)
            {
                if (!new_answer.Contains(x)) new_answer.Add(x);
            }
            foreach (var x in new_answer) Write(x + " ");
        }
    }
}
