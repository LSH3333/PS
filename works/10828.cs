using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;

namespace Project1
{
    class Stack
    {
        public int[] arr;
        public int ptr;

        public Stack()
        {
            arr = new int[10001];
            ptr = -1;
        }

        public void push(int x)
        {
            arr[++ptr] = x;
        }

        public int pop()
        {
            if (ptr == -1) return -1;
            return arr[ptr--];
        }

        public int size()
        {
            return ptr + 1;
        }

        public int empty()
        {
            if (ptr == -1) return 1;
            else return 0;
        }

        public int top()
        {
            if (ptr == -1) return -1;
            return arr[ptr];
        }
    }

    public class Class1
    {

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();

            Stack stack = new Stack();
            int N = int.Parse(sr.ReadLine());

            while(N-- > 0)
            {
                string[] _s = sr.ReadLine().Split(' ');
                string op = _s[0];

                if(op == "push")
                {
                    int x = int.Parse(_s[1]);
                    stack.push(x);
                }
                else if(op == "pop")
                {
                    sb.Append(stack.pop()).Append('\n');
                }
                else if(op == "size")
                {
                    sb.Append(stack.size()).Append('\n');
                }
                else if(op == "empty")
                {
                    sb.Append(stack.empty()).Append('\n');
                }
                else if(op == "top")
                {
                    sb.Append(stack.top()).Append('\n');
                }
            }
            Write(sb);

        }       
    }
}
