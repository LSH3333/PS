import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[15][15];
        // 0층
        for(int i = 1; i < 15; i++) arr[0][i] = i;
        // 1호
        for(int i = 0; i < 15; i++) arr[i][1] = 1;

        for(int i = 1; i < 15; i++)
        {
            for(int j = 1; j < 15; j++)
            {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }

        int t = sc.nextInt();
        while(t-- > 0)
        {
            int n = sc.nextInt(); int k = sc.nextInt();
            System.out.println(arr[n][k]);
        }

    }
}
