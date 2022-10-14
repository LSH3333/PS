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
            int[] arr = new int[101];
            int N = int.Parse(ReadLine());
            for(int i = 0; i < N; i++)
            {
                int num = int.Parse(ReadLine());
                arr[i] = num;
            }

            int answer = 0;
            for(int i = N-2; i >= 0; i--)
            {
                if(arr[i] >= arr[i+1])
                {
                    int sub = arr[i] - arr[i + 1] + 1;
                    answer += sub;
                    arr[i] -= sub;
                }
            }
            Write(answer);
        }       
    }
}
