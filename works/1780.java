import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;



public class Main
{
    static int[][] arr = new int[3000][3000];
    static int[] answer = new int[3];

    static void Cal(int n, int r, int c)
    {
        int num = arr[r][c];
        boolean trigger = true;
        for(int i = r; i < r+n; i++)
        {
            for(int j = c; j < c+n; j++)
            {
                if(arr[i][j] != num) { trigger = false; break;}
            }
        }
        // 한가지 숫자로만 채워져 있음
        if(trigger)
        {
            answer[num+1]++;
            return;
        }

        for(int i = r; i < r+n; i+=n/3)
        {
            for(int j = c; j < c+n; j+=n/3)
            {
                Cal(n/3, i, j);
            }
        }

    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        String[] _s;
        for(int i = 0; i < N; i++)
        {
            _s = br.readLine().split(" ");
            for(int j = 0; j < N; j++)
            {
                arr[i][j] = Integer.parseInt(_s[j]);
            }
        }

        Cal(N, 0, 0);

        for(int i = 0; i < 3; i++) System.out.println(answer[i]);
    }
}
