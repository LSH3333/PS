import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;



public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        int N = Integer.parseInt(_s[0]);
        int L = Integer.parseInt(_s[1]);
        int[] a = new int[N];
        _s = br.readLine().split( " ");

        for(int i = 0; i < N; i++) a[i] = Integer.parseInt(_s[i]);
        Arrays.sort(a);

        double end = a[0] - 0.5 + L;
        int cnt = 1;
        for(int i = 1; i < N; i++)
        {
            if(a[i] + 0.5 <= end) continue;
            else
            {
                cnt++;
                end = a[i] - 0.5 + L;
            }
        }
        System.out.print(cnt);
    }
}
