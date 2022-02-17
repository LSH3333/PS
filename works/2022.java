import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static double x, y, c;
    static double epsilon = 0.000001;

    static double Cal(double mid)
    {
        double h1 = Math.sqrt(x * x - mid * mid);
        double h2 = Math.sqrt(y * y - mid * mid);
        return (h1 * h2) / (h1 + h2);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        x = Double.parseDouble(_s[0]);
        y = Double.parseDouble(_s[1]);
        c = Double.parseDouble(_s[2]);

        double low = 0;
        double high = Math.min(x, y);
        double result =0;

        while(high - low > epsilon)
        {
            // w1 + w2
            double mid = (low + high) / 2.0;

            if(Cal(mid) >= c)
            {
                result = mid;
                low = mid;
            }
            else
                high = mid;
        }
        System.out.printf("%.3f", result);
    }

}
