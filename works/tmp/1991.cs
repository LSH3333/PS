using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Node
    {
        public char root;
        public char left;
        public char right;
        public Node(char _root, char _left, char _right)
        { root = _root; left = _left; right = _right; }
    }

    class Program
    {
        static ArrayList pre = new ArrayList();
        static ArrayList inorder = new ArrayList();
        static ArrayList post = new ArrayList();
        static Dictionary<char, Node> map = new Dictionary<char, Node>();

        static void PreOrder(char root)
        {
            if (root == '.') return;
            pre.Add(root);
            PreOrder(map[root].left);
            PreOrder(map[root].right);
        }

        static void PostOrder(char root)
        {
            if (root == '.') return;
            PostOrder(map[root].left);
            PostOrder(map[root].right);
            post.Add(root);
        }

        static void InOrder(char root)
        {
            if (root == '.') return;
            InOrder(map[root].left);
            inorder.Add(root);
            InOrder(map[root].right);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int n = int.Parse(sr.ReadLine());
            string[] _s;
            for (int i = 0; i < n; i++)
            {
                _s = sr.ReadLine().Split(' ');
                map[_s[0][0]] = new Node(_s[0][0], _s[1][0], _s[2][0]);
            }

            PreOrder('A');
            PostOrder('A');
            InOrder('A');

            foreach (var x in pre) Write(x);
            WriteLine();
            foreach (var x in inorder) Write(x);
            WriteLine();
            foreach (var x in post) Write(x);
        }


    }

}
