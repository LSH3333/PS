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

        int N = sc.nextInt();
        int M = sc.nextInt();
        long[] trees = new long[N];

        long left = 0, right = 0;
        for(int i = 0; i < N; i++)
        {
            trees[i] = sc.nextLong();
            right = Math.max(right, trees[i]);
        }

        long answer = 0;
        Arrays.sort(trees);

        while(left <= right)
        {
            long mid = (left + right) / 2;

            long sum = 0;
            for(int i = 0; i < N; i++)
            {
                if(trees[i] > mid) sum += (trees[i] - mid);
            }

            if(sum < M)
            {
                // 절단기 아래로
                right = mid - 1;
            }
            else
            {
                // 절단기 위로
                left = mid + 1;
                answer = mid;
            }
        }
        System.out.print(answer);
    }
}
