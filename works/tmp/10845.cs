using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;

namespace Project1
{
    class Queue
    {
        public int MAX = 10100;
        public int[] arr;
        public int f;
        public int b;

        public Queue()
        {
            arr = new int[MAX];
            f = 0; b = 0;
        }

        private int nextPos(int i)
        {
            if (i + 1 == MAX) return 0;
            else return i + 1;
        }

        public void push(int x)
        {
            b = nextPos(b);
            arr[b] = x;
        }

        public int pop()
        {
            if (b == f) return -1;
            f = nextPos(f);
            return arr[f];
        }

        public int size()
        {
            if (f == b) return 0;
            else if (f < b) return b - f;
            else return (MAX - f - 1) + (b - 1);
        }

        public int empty()
        {
            if (b == f) return 1;
            else return 0;
        }

        public int front()
        {
            if (f == b) return -1;
            return arr[nextPos(f)];
        }

        public int back()
        {
            if (f == b) return -1;
            return arr[b];
        }
    }

    public class Class1
    {

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();

            Queue queue = new Queue();
            int N = int.Parse(sr.ReadLine());

            while(N-- > 0)
            {
                string[] _s = sr.ReadLine().Split(' ');
                string op = _s[0];

                if(op == "push")
                {
                    int x = int.Parse(_s[1]);
                    queue.push(x);
                }
                else if(op == "pop")
                {
                    sb.Append(queue.pop()).Append('\n');
                }
                else if(op == "size")
                {
                    sb.Append(queue.size()).Append('\n');
                }
                else if(op == "empty")
                {
                    sb.Append(queue.empty()).Append('\n');
                }
                else if(op == "front")
                {
                    sb.Append(queue.front()).Append('\n');
                }
                else if (op == "back")
                {
                    sb.Append(queue.back()).Append('\n');
                }
            }
            Write(sb);

        }       
    }
}
