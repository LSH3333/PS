import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long finger = Long.parseLong(br.readLine());
        long num = Long.parseLong(br.readLine());
        long ans = 0;
        long goAndReturn = 0;

        if(finger == 1)
        {
            // 왕복할수 있는 횟수
            goAndReturn = num - 1;
            ans = 1 + (8 * goAndReturn);
            ans += 7;
        }
        else if(finger == 5)
        {
            goAndReturn = num;
            ans = 1 + (8 * goAndReturn);
            ans += 3;
        }
        else
        {
            goAndReturn = num / 2;
            ans = 1 + (8 * goAndReturn);
            if(num % 2 == 0)
            {
                ans += finger-2;
            }
            else
            {
                ans += 7 - finger + 1;
            }
        }
        System.out.print(ans);
    }

}
