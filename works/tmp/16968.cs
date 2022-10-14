using static System.Console;
using System;
using System.Collections;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            string str = ReadLine();
            int sum = 0;            
            sum = (str[0] == 'd') ? 10 : 26;

            for(int i = 1; i < str.Length; i++)
            {
                if(str[i] == str[i-1])
                {
                    if (str[i] == 'd') sum *= 9;
                    else sum *= 25;
                }
                else
                {
                    if (str[i] == 'd') sum *= 10;
                    else sum *= 26;
                }                
            }
            Write(sum);
        }
    }
}
