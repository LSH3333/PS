using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using System.Text;

namespace ConsoleApp
{
    class Point
    {
        public double x, y, z;
        public Point(double _x, double _y, double _z)
        {
            x = _x; y = _y; z = _z;
        }
    }

    class Program
    {
        static double CalDistance(Point a, Point b)
        {
            return Math.Sqrt(Math.Pow(a.x - b.x, 2) + Math.Pow(a.y - b.y, 2) + Math.Pow(a.z - b.z, 2));
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            double Ax = int.Parse(_s[0]);
            double Ay = int.Parse(_s[1]);
            double Az = int.Parse(_s[2]);

            double Bx = int.Parse(_s[3]);
            double By = int.Parse(_s[4]);
            double Bz = int.Parse(_s[5]);

            double Cx = int.Parse(_s[6]);
            double Cy = int.Parse(_s[7]);
            double Cz = int.Parse(_s[8]);

            Point a = new Point(Ax, Ay, Az);
            Point b = new Point(Bx, By, Bz);
            Point c = new Point(Cx, Cy, Cz);
            Point zero = new Point(0, 0, 0);

            double minDistance = CalDistance(zero, new Point(10000, 10000, 10000));
            int t = 1000000;

            while (t-- > 0)
            {
                Point mid = new Point((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
                double dis = CalDistance(mid, c);
                if (dis < minDistance) minDistance = dis;

                double acDis = CalDistance(a, c);
                double bcDis = CalDistance(b, c);

                if (acDis <= bcDis)
                    b = mid;
                else
                    a = mid;
            }
            Write(minDistance);
        }

    }
}
