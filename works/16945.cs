using static System.Console;
using System;
using System.Collections;
using System.Text;
using System.IO;
using System.Collections.Generic;

namespace Project1
{
    public class Class1
    {
        static bool[] mark = new bool[10];
        static int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        static List<int> v = new List<int>();
        static List<int> nums = new List<int>();
        static int answer = 99999;

        static bool IsItMagicS()
        {
            if (v[0] + v[1] + v[2] != 15) return false;
            if (v[3] + v[4] + v[5] != 15) return false;
            if (v[6] + v[7] + v[8] != 15) return false;

            if (v[0] + v[3] + v[6] != 15) return false;
            if (v[1] + v[4] + v[7] != 15) return false;
            if (v[2] + v[5] + v[8] != 15) return false;

            if (v[0] + v[4] + v[8] != 15) return false;
            if (v[2] + v[4] + v[6] != 15) return false;

            return true;
        }

        static void DFS(int depth)
        {
            if(depth == 9)
            {
                if(IsItMagicS())
                {
                    int sum = 0;
                    for (int i = 0; i < 9; i++) sum += Math.Abs(nums[i] - v[i]);
                    answer = Math.Min(answer, sum);
                }
                return;
            }

            for(int i = 0; i < 9; i++)
            {
                if (mark[i]) continue;
                mark[i] = true;
                v.Add(arr[i]);
                DFS(depth + 1);
                v.RemoveAt(v.Count - 1);
                mark[i] = false;
            }
        }

        public static void Main(string[] args)
        {
            for(int i = 0; i < 3; i++)
            {
                string[] s = ReadLine().Split(' ');
                nums.Add(int.Parse(s[0]));
                nums.Add(int.Parse(s[1]));
                nums.Add(int.Parse(s[2]));
            }

            DFS(0);

            Write(answer);
        }
    }
}
