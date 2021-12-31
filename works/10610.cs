using static System.Console;
using System;
using System.Collections;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            string n = ReadLine();

            int sum = 0;
            bool isZero = false;
            for(int i = 0; i < n.Length; i++)
            {
                if (n[i] == '0') isZero = true;
                sum += n[i] - '0';
            }

            if (sum % 3 == 0 && isZero)
            {
                char[] arr = n.ToCharArray();
                Array.Sort(arr);
                Array.Reverse(arr);
                Write(new string(arr));
            }
            else
                Write(-1);

        }
    }
}
