using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;

namespace Project1
{
    class Pair
    {
        public int first, second;
        public Pair(int _first, int _second) { first = _first; second = _second; }
    }

    class Tuple
    {
        public int x, y, z;
        public Tuple(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
    }


    public class Class1
    {
        static int ChangeToSec(string time)
        {
            string m = time.Substring(0, 2);
            string s = time.Substring(3);
            int m_int = int.Parse(m);
            int s_int = int.Parse(s);
            return m_int * 60 + s_int;
        }

        static string ChangeToMin(int time)
        {
            int m = time / 60;
            int s = time % 60;
            string m_str = Convert.ToString(m);
            string s_str = Convert.ToString(s);
            if (m_str.Length == 1) m_str = "0" + m_str;
            if (s_str.Length == 1) s_str = "0" + s_str;
            return m_str + ":" + s_str;
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());

            List<Pair> goal = new List<Pair>();
            int N = int.Parse(sr.ReadLine());
            for(int i = 0; i < N; i++)
            {
                string[] _s = sr.ReadLine().Split(' ');
                int team = int.Parse(_s[0]);
                string time = _s[1];
                goal.Add(new Pair(team, ChangeToSec(time)));
            }
            goal.Add(new Pair(0, 60 * 48));

            int t1 = 0, t2 = 0;
            List<Tuple> v = new List<Tuple>();
            for(int i = 0; i < N; i++)
            {
                if (goal[i].first == 1) t1++; else t2++;
                if (t1 == t2) continue;
                int winning = t1 > t2 ? 1 : 2;
                v.Add(new Tuple(goal[i].second, goal[i + 1].second, winning));                
            }

            int t1Time = 0;
            int t2Time = 0;
            foreach(Tuple tuple in v)
            {
                if (tuple.z == 1) t1Time += tuple.y - tuple.x;
                else t2Time += tuple.y - tuple.x;
            }
            WriteLine(ChangeToMin(t1Time));
            WriteLine(ChangeToMin(t2Time));
        }       
    }
}
