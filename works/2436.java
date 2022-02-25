import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static long GCD(long a, long b)
    {
        if(b == 0) return a;
        return GCD(b, a%b);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        long gcd = Long.parseLong(_s[0]);
        long lcm = Long.parseLong(_s[1]);
        long a=0, b=0;

        lcm /= gcd;
        for(long i = 1; i * i <= lcm; i++)
        {
            if(lcm % i != 0) continue;
            long a_tmp = i;
            long b_tmp = lcm / i;

            if(GCD(a_tmp, b_tmp) == 1)
            {
                a = a_tmp;
                b = b_tmp;
            }
        }
        System.out.print(a*gcd + " " + b*gcd);
    }

}
