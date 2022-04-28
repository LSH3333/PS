import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;



public class Main
{
    final static int MAX = 1000010;
    static int[] p = new int[MAX];

    static void FindPrime()
    {
        for(int i = 2; i < MAX; i++) p[i] = i;

        for(int i = 2; i * i < MAX; i++)
        {
            if(p[i] == 0) continue;
            for(int j = i*i; j < MAX; j += i) p[j] = 0;
        }
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = sc.nextInt();
        int m = sc.nextInt();

        FindPrime();
        for(int i = n; i <= m; i++)
        {
            if(p[i] == 0) continue;
            sb.append(p[i]).append('\n');
        }
        System.out.print(sb);
    }
}
