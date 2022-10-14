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
            int N = int.Parse(ReadLine());
            int w = 4 * N - 3;
            int h = 2 * N - 1;
            int mid = w - N * 2; // 가운데 공백           
            List<List<char>> board = new List<List<char>>();

            //
            List<char> a = new List<char>();
            for (int i = 0; i < N; i++) a.Add('*');
            for (int i = 0; i < mid; i++) a.Add(' ');
            for (int i = 0; i < N; i++) a.Add('*');
            board.Add(a);
            mid -= 2;

            int l = 0;
            for (int i = 1; i < N; i++)
            {
                a = new List<char>();
                for (int j = 0; j < i; j++) a.Add(' ');
                a.Add('*');
                for (int j = 0; j < N - 2; j++) a.Add(' ');
                a.Add('*');
                for (int j = 0; j < mid; j++) a.Add(' ');
                if (mid > 0) a.Add('*');
                mid -= 2;
                for (int j = 0; j < N - 2; j++) a.Add(' ');
                a.Add('*');
                l = i - 1;
                board.Add(a);
            }
            mid = 1;

            for (int i = N; i < h - 1; i++)
            {
                a = new List<char>();
                for (int j = 0; j < l; j++) a.Add(' ');
                l--;
                a.Add('*');
                for (int j = 0; j < N - 2; j++) a.Add(' ');
                a.Add('*');
                for (int j = 0; j < mid; j++) a.Add(' ');
                mid += 2;
                a.Add('*');
                for (int j = 0; j < N - 2; j++) a.Add(' ');
                a.Add('*');
                board.Add(a);
            }

            a = new List<char>();
            for (int i = 0; i < N; i++) a.Add('*');
            for (int i = 0; i < mid; i++) a.Add(' ');
            for (int i = 0; i < N; i++) a.Add('*');
            board.Add(a);


            foreach(var o in board)
            {
                foreach(char c in o)
                {
                    Write(c);
                }
                WriteLine();
            }
        }
        
    }
}
