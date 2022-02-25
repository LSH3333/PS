import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main
{
    static int CCW(long x1, long y1, long x2, long y2, long x3, long y3)
    {
        long a = x1*y2 + x2*y3 + x3*y1;
        long b = x2*y1 + x3*y2 + x1*y3;

        if(a-b > 0) return 1;
        else return -1;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        long x1 = sc.nextInt(); long y1 = sc.nextInt();
        long x2 = sc.nextInt(); long y2 = sc.nextInt();
        long x3 = sc.nextInt(); long y3 = sc.nextInt();
        long x4 = sc.nextInt(); long y4 = sc.nextInt();

        int abc = CCW(x1, y1, x2, y2, x3, y3);
        int abd = CCW(x1, y1, x2, y2, x4, y4);

        int dca = CCW(x4, y4, x3, y3, x1, y1);
        int dcb = CCW(x4, y4, x3, y3, x2, y2);

        if(abc * abd < 0 && dca * dcb < 0) System.out.print(1);
        else System.out.print(0);
    }

}
