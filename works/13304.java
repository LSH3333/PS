import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Set;
import java.util.HashSet;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); int K = sc.nextInt();
        int[][] arr = new int[7][2];
        for(int i = 0; i < N; i++)
        {
            int gender = sc.nextInt();
            int grade = sc.nextInt();
            arr[grade][gender]++;
        }

        int[] v = new int[5];
        v[0] = arr[1][0] + arr[1][1] + arr[2][0] + arr[2][1];
        v[1] = arr[3][0] + arr[4][0];
        v[2] = arr[3][1] + arr[4][1];
        v[3] = arr[5][0] + arr[6][0];
        v[4] = arr[5][1] + arr[6][1];

        int ans = 0;
        for(int x : v)
        {
            ans += x / K;
            if(x % K != 0) ans++;
        }
        System.out.print(ans);
    }
}
