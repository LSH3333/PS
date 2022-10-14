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
        int[] arr = new int[10001];

        int N = Integer.parseInt(br.readLine());
        int maxVal = 0;
        String[] _s = br.readLine().split(" ");
        for(int i = 0; i < N; i++)
        {
            arr[i] = Integer.parseInt(_s[i]);
            if(arr[i] > maxVal) maxVal = arr[i];
        }
        int M = Integer.parseInt(br.readLine());

        int left = 0, right = maxVal, answer = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int sum = 0;
            for(int i = 0; i < N; i++)
            {
                if(arr[i] > mid) sum += mid;
                else sum += arr[i];
            }

            if(sum <= M)
            {
                left = mid + 1;
                answer = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        System.out.print(answer);
    }
}
