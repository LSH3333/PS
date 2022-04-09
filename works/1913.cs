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
            StringBuilder sb = new StringBuilder();
            int[] dr = { 1, 0, -1, 0 };
            int[] dc = { 0, 1, 0, -1 };
            int N = int.Parse(ReadLine());
            int num = int.Parse(ReadLine());
            int cnt = N * N;           
            int r = 0, c = 0, dir = 0, ansR = 0, ansC = 0;
            int[,] v = new int[N,N];

            while(cnt > 0)
            {
                if(cnt == num) { ansR = r; ansC = c; }
                v[r, c] = cnt;
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N || v[nr,nc] != 0)
                {
                    dir = (dir + 1) % 4;
                    nr = r + dr[dir];
                    nc = c + dc[dir];
                }
                r = nr; c = nc;
                cnt--;
            }

            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    sb.Append(v[i, j]);
                    sb.Append(' ');
                } sb.Append('\n');
            }
            sb.Append(ansR + 1); sb.Append(' '); sb.Append(ansC + 1);
            Write(sb);
        }
        
    }
}
