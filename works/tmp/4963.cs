using System;
using System.Collections.Generic;
using System.Collections;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        public static int w, h;
        public static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
        public static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };
        public static int[,] arr;
        public static bool[,] mark;

        public static void dfs(int r, int c)
        {
            if (mark[r, c]) return;

            mark[r, c] = true;
            for (int i = 0; i < 8; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if (arr[nr, nc] != 1) continue;
                dfs(nr, nc);
            }
        }

        static void Main(string[] args)
        {
            while(true)
            {
                string tmp = ReadLine();
                string[] s_tmp = tmp.Split(" ");
                w = int.Parse(s_tmp[0]);
                h = int.Parse(s_tmp[1]);
                if (w == 0 && h == 0) return;
                int ans = 0;
                arr = new int[h, w];
                mark = new bool[h, w];

                for(int i = 0; i < h; i++)
                {
                    tmp = ReadLine();
                    s_tmp = tmp.Split(" ");
                    for(int j = 0; j < w; j++)
                    {
                        arr[i, j] = int.Parse(s_tmp[j]);
                    }
                }

                for(int i = 0; i < h; i++)
                {
                    for(int j = 0; j < w; j++)
                    {
                        if (arr[i, j] != 1 || mark[i,j]) continue;
                        dfs(i, j);
                        ans++;
                    }
                }
                WriteLine(ans);
            }
        }

    }
}
