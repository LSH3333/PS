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
        long[] len = new long[10001];
        int K = sc.nextInt();
        int N = sc.nextInt();

        long left = 0, right = 0;
        for(int i = 0; i < K; i++)
        {
            len[i] = sc.nextInt();
            right += len[i];
        }

        long answer = 0;
        while(left <= right)
        {
            long mid = (left + right) / 2;
            if(mid == 0) mid++;

            long cnt = 0;
            for(int i = 0; i < K; i++) cnt += (len[i] / mid);

            if(cnt < N)
            {
                right = mid - 1;
            }
            else // N개 이상 민들수 있음
            {
                left = mid + 1;
                answer = Math.max(mid, answer);
            }
        }
        System.out.print(answer);
    }
}
