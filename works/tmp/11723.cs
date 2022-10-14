using static System.Console;
using System;
using System.Collections;
using System.Text;
using System.IO;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
            StringBuilder sb = new StringBuilder();

            bool[] S = new bool[21];
            int m = int.Parse(sr.ReadLine());


            while (m-- > 0)
            {
                string order = sr.ReadLine();
                string op; int num = 0;

                int id = order.IndexOf(' ');
                if(id == -1)
                {
                    op = order;
                }
                else
                {
                    op = order.Substring(0, id);
                    num = int.Parse(order.Substring(id + 1));
                }


                if (op.Equals("add"))
                {
                    S[num] = true;
                }
                else if (op.Equals("remove"))
                {
                    S[num] = false;
                }
                else if (op.Equals("check"))
                {
                    if (S[num]) sw.WriteLine(1);
                    else sw.WriteLine(0);
                }
                else if (op.Equals("toggle"))
                {
                    S[num] = !S[num];
                }
                else if (op.Equals("all"))
                {
                    for (int i = 0; i < 21; i++) S[i] = true;
                }
                else if (op.Equals("empty"))
                {
                    for (int i = 0; i < 21; i++) S[i] = false;
                }
            }
            sw.Close();
            sr.Close();
        }
    }
}
