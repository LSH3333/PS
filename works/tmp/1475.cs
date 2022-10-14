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
            string number = sr.ReadLine();
            int[] nums = new int[10];
            for (int i = 0; i < number.Length; i++) nums[number[i] - '0']++;
            int a = 0, b = 0;
            for(int i = 0; i < 10; i++)
            {
                if (i == 6 || i == 9) continue;
                a = Math.Max(a, nums[i]);
            }
            b = nums[6] + nums[9];
            if (b % 2 != 0) b = b / 2 + 1;
            else b /= 2;
            Write(Math.Max(a, b));
        }
    }
}
