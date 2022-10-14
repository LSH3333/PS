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
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int[] arr = new int[10001];
            int N = int.Parse(sr.ReadLine());
            int maxVal = 0;
            string[] _s = sr.ReadLine().Split(' ');

            for(int i = 0; i < N; i++)
            {
                arr[i] = int.Parse(_s[i]);
                if (arr[i] > maxVal) maxVal = arr[i];
            }
            int M = int.Parse(sr.ReadLine());

            int left = 0, right = maxVal, answer = 0;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                int sum = 0;
                for (int i = 0; i < N; i++)
                {
                    if (arr[i] > mid) sum += mid;
                    else sum += arr[i];
                }

                if (sum <= M)
                {
                    left = mid + 1;
                    answer = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            Write(answer);
        }       
    }
}
