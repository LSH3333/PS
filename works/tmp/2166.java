import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main
{
    static double[][] cord = new double[10001][2];

    static double CCW(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        double a = x1*y2 + x2*y3 + x3*y1;
        double b = x2*y1 + x3*y2 + x1*y3;

        return (a-b)/2;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s;
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++)
        {
            _s = br.readLine().split(" ");
            cord[i][0] = Double.parseDouble(_s[0]);
            cord[i][1] = Double.parseDouble(_s[1]);
        }

        double sum = 0;
        for(int i = 1; i < n-1; i++)
        {
            sum += CCW(cord[0][0], cord[0][1], cord[i][0], cord[i][1], cord[i+1][0], cord[i+1][1]);
        }

//        System.out.print(Math.abs(Math.round(sum*100)/100.0));
        System.out.format("%.1f", Math.abs(sum));
    }

}
