import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = sc.nextInt();
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int[] v = new int[n];
            double avg = 0;
            for(int i = 0; i < n; i++)
            {
                int num = sc.nextInt();
                v[i] = num;
                avg += num;
            }
            avg /= n;

            double over = 0;
            for(int i = 0; i < n; i++) if(v[i] > avg) over++;

            double answer = over / n;
            answer *= 100;
            System.out.printf("%.3f%%\n", answer);
        }
    }
}
