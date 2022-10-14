import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        boolean[][] arr = new boolean[1010][1010];
        for(int i = 0; i < 1010; i++)
            for(int j = 0; j < 1010; j++)
                arr[i][j] = true;
        arr[0][0] = false;

        for(int i = 0; i <= 1000; i++)
        {
            for(int j = 0; j <= 1000; j++)
            {
                if(i == 0 && j == 0) continue;
                if(!arr[i][j]) continue;

                int a = i, b = j;
                while(true)
                {
                    a += i; b += j;
                    if(a > 1000 || b > 1000) break;
                    arr[a][b] = false;
                }
            }
        }

        int[] answer = new int[1010];
        int cnt = 0;
        for(int i = 0; i <= 1000; i++)
        {
            for(int a = 0; a < i; a++)
            {
                if(arr[i][a]) cnt++;
                if(arr[a][i]) cnt++;
            }
            if(arr[i][i]) cnt++;

            answer[i] = cnt;
        }

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0)
        {
            int N = sc.nextInt();
            System.out.println(answer[N]);
        }
    }
}
