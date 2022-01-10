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

        if(n == 1) {System.out.print(0); return;}

        d[0] = 0;
        for(int i = 1; i < n; i++)
        {
            int lowest = 2000000000;
            boolean trigger = false;
            for(int j = 0; j < i; j++)
            {
                if(j + a[j] >= i) { lowest = Math.min(lowest, d[j]+1); trigger = true; }
            }
            if(!trigger) { System.out.print(-1); return; }
            d[i] = lowest;
        }

        System.out.print(d[n-1]);
    }

}
