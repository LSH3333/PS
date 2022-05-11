using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using System.Text;

namespace ConsoleApp
{
    class Program
    {
        static int N;
        static int rSize;
        static int cSize;

        static void Draw(int r, int c, int cnt, int depth, char[,] stars)
        {
            stars[r, c] = '*';

            for (int i = 0; i < cnt - 1; i++)
            {
                r--;
                stars[r, c] = '*';
            }
            for (int i = 0; i < cnt - 1; i++)
            {
                c++;
                if (c >= cSize) break;
                stars[r, c] = '*';
            }

            if (depth == N - 1) return;

            for (int i = 0; i < cnt + 2 - 1; i++)
            {
                r++;
                stars[r, c] = '*';
            }

            for (int i = 0; i < cnt + 2 - 1; i++)
            {
                c--;
                stars[r, c] = '*';
            }

            Draw(r, c, cnt + 4, depth + 1, stars);
        }

        static void Print(char[,] stars)
        {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < rSize; i++)
            {
                if (i == 1)
                    sb.Append('*').Append('\n');
                else
                {
                    for (int j = 0; j < cSize; j++)
                        sb.Append(stars[i, j]);
                    sb.Append('\n');
                }
            }

            Write(sb);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            N = int.Parse(sr.ReadLine());
            if (N == 1) { Write('*'); return; }

            rSize = 4 * N - 2 + 1;
            cSize = 4 * N - 4 + 1;
            char[,] stars = new char[rSize, cSize];

            for (int i = 0; i < rSize; i++)
            {
                for (int j = 0; j < cSize; j++)
                {
                    stars[i, j] = ' ';
                }
            }

            Draw(2 * N, 2 * N - 2, 3, 0, stars);
            Print(stars);
        }

    }
}
