using System.Collections;
using System.Collections.Generic;
using static System.Console;
using System.Text;

namespace Project1
{
    public class Class1
    {
        static int N, M, ans;
        static int[][] arr = new int[55][];
        static int[][] mark = new int[55][];
        static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
        static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };


        static void bfs(int r, int c)
        {
            //Queue<KeyValuePair<int, int>> q = new Queue<KeyValuePair<int, int>>();
            Queue<int[]> q = new Queue<int[]>();
            q.Enqueue(new int[] { r, c });
            mark[r][c] = 1;            
            
            while(q.Count != 0)
            {
                int[] temp = q.Dequeue();
                int nr = temp[0];
                int nc = temp[1];

                if(arr[nr][nc] == 1)
                {                    
                    if (mark[nr][nc] - 1 > ans) ans = mark[nr][nc] - 1;                    
                    break;
                }

                for(int i = 0; i < 8; i++)
                {
                    int nnr = nr + dr[i];
                    int nnc = nc + dc[i];

                    if ((nnr < 0) || (nnr >= N) || (nnc < 0) || (nnc > M)) continue;
                    if (mark[nnr][nnc] != 0) continue;
                    q.Enqueue(new int[] { nnr, nnc });
                    mark[nnr][nnc] = mark[nr][nc] + 1;

                }
            }
        }

        public static void Main(string[] args)
        {
            string[] s = ReadLine().Split(' ');
            N = int.Parse(s[0]); M = int.Parse(s[1]);
            for (int i = 0; i < 55; i++) arr[i] = new int[55];

            for(int i = 0; i < N; i++)
            {
                s = ReadLine().Split();
                for(int j = 0; j < M; j++)
                {
                    arr[i][j] = int.Parse(s[j]);
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (arr[i][j] == 1) continue;
                    mark = new int[55][];
                    for (int a = 0; a < 55; a++) mark[a] = new int[55];
                    bfs(i, j);
                }
            }
            Write(ans);
        }

        
    }
}
