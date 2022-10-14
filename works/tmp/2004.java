import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static long Cal(long n, long div)
    {
        long cnt = 0;
        while(n > 0)
        {
            n /= div;
            cnt += n;
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        long n = Long.parseLong(_s[0]);
        long m = Long.parseLong(_s[1]);

        long a = Cal(n,2) - (Cal(m,2) + Cal(n-m,2));
        long b = Cal(n, 5) - (Cal(m,5) + Cal(n-m, 5));
        System.out.print(Math.min(a,b));
    }

}
