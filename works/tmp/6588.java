import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static final int MAX = 1000001;
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

        FindPrimeNumbers();

        while(true)
        {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            int a = -1;
            int b = -1;
            for(int i = 1; i < n; i+=2)
            {
                if(primeNumber[i] != 0 && primeNumber[n-i] != 0)
                {
                    a = i;
                    b = n-i;
                    break;
                }
            }
            if(a == -1 && b == -1)
                System.out.println("Goldbach's conjecture is wrong.");
            else
                System.out.println(n + " = " + a + " + " + b);
        }

    }

}
