import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String tmp[] = br.readLine().split(" ");
        int[] a = new int[n+1];
        int[] d = new int[n+1];
        for(int i = 0; i < n; i++) a[i] = Integer.parseInt(tmp[i]);

        d[0] = a[0];
        int answer = d[0];
        for(int i = 1; i < n; i++)
        {
            int highest = 0;
            for(int j = 0; j < i; j++)
            {
                if(a[j] < a[i]) highest = Math.max(highest, d[j]);
            }
            d[i] = highest + a[i];
            answer = Math.max(answer, d[i]);
        }
        System.out.print(answer);
    }

}
