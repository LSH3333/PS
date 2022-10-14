import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[101];

        int N = sc.nextInt();
        for(int i = 0; i < N; i++)
        {
            int num = sc.nextInt();
            arr[i] = num;
        }

        int answer = 0;
        for(int i = N-2; i >= 0; i--)
        {
            if(arr[i] >= arr[i+1])
            {
                int sub = arr[i] - arr[i+1] + 1;
                answer += sub;
                arr[i] -= sub;
            }
        }
        System.out.print(answer);
    }
}
