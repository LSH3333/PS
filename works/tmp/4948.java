import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static final int MAX = 123456 * 2 + 10;
    static int[] primeNumber = new int[MAX];

    static void FindPrimeNumbers()
    {
        for(int i = 2; i < MAX; i++)
        {
            primeNumber[i] = i;
        }

        for(int i = 2; i < Math.sqrt(MAX); i++)
        {
            if(primeNumber[i] == 0) continue;
            for(int j = i * i; j < MAX; j += i)
            {
                primeNumber[j] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = -1;
        FindPrimeNumbers();
        while(true)
        {
            n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            int cnt = 0;
            for(int i = n+1; i <= 2 * n; i++)
                if(primeNumber[i] != 0) cnt++;
            System.out.println(cnt);
        }

    }

}
