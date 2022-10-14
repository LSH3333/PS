import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

class Point
{
    double x, y, z;
    public Point(double _x, double _y, double _z)
    {
        x = _x; y = _y; z = _z;
    }
}

public class Main
{
    static double CalDistance(Point a, Point b)
    {
        return Math.sqrt(Math.pow(a.x-b.x, 2) + Math.pow(a.y-b.y,2) + Math.pow(a.z-b.z,2));
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        double Ax = Integer.parseInt(_s[0]);
        double Ay = Integer.parseInt(_s[1]);
        double Az = Integer.parseInt(_s[2]);

        double Bx = Integer.parseInt(_s[3]);
        double By = Integer.parseInt(_s[4]);
        double Bz = Integer.parseInt(_s[5]);

        double Cx = Integer.parseInt(_s[6]);
        double Cy = Integer.parseInt(_s[7]);
        double Cz = Integer.parseInt(_s[8]);

        Point a = new Point(Ax, Ay, Az);
        Point b = new Point(Bx, By, Bz);
        Point c = new Point(Cx, Cy, Cz);
        Point zero = new Point(0, 0, 0);

        double minDistance = CalDistance(zero, new Point(10000,10000,10000));
        int t = 1000000;
        while(t-- > 0)
        {
            Point mid = new Point((a.x+b.x)/2, (a.y+b.y)/2, (a.z+b.z)/2);
            double dis = CalDistance(mid, c);
            if(dis < minDistance) minDistance = dis;

            double acDis = CalDistance(a, c);
            double bcDis = CalDistance(b, c);

            if(acDis <= bcDis)
                b = mid;
            else
                a = mid;
        }
        System.out.print(minDistance);
    }
}
