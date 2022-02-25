import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int x1, y1, x2, y2, x3, y3;
        x1 = sc.nextInt(); y1 = sc.nextInt();
        x2 = sc.nextInt(); y2 = sc.nextInt();
        x3 = sc.nextInt(); y3 = sc.nextInt();

        int a = x1*y2 + x2*y3 + x3*y1;
        int b = x2*y1 + x3*y2 + x1*y3;
        int cal = a - b;

        if(cal == 0) System.out.print(0);
        else if(cal > 0) System.out.print(1);
        else System.out.print(-1);
    }

}
