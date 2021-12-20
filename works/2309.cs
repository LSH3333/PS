using static System.Console;
using System;
using System.Collections;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            int[] arr = new int[10];
            int sum = 0;
            for(int i = 0; i < 9; i++)
            {
                arr[i] = int.Parse(ReadLine());
                sum += arr[i];
            }
            sum -= 100;

            int target1 = 0, target2 = 0;
            for(int i = 0; i < 9; i++)
            {
                for(int j = i + 1; j < 9; j++)
                {
                    if (arr[i] + arr[j] == sum)
                    {
                        target1 = i; target2 = j;
                        break;
                    }
                }
            }

            ArrayList ans = new ArrayList();
            for(int i = 0; i < 9; i++)
            {
                if (i == target1 || i == target2) continue;
                ans.Add(arr[i]);
            }
            ans.Sort();

            foreach (var x in ans) WriteLine(x);
        }
    }
}
