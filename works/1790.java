import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static int GetPos(int n)
    {
        int len = 1;
        int val = n;
        int cnt = 0;
        int num = 1;

        while(val > 0)
        {
            if(val / 10 == 0)
            {
                cnt += (n - len + 1) * num;
                break;
            }
            else
            {
                cnt += 9 * len * num;
                len *= 10;
                num++;
                val /= 10;
            }
        }
        // 자릿수
        return cnt;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        int n = Integer.parseInt(_s[0]);
        int k = Integer.parseInt(_s[1]);

        int nPos = GetPos(n);
        if(k > nPos) { System.out.print(-1); return; }

        int cnt = 0;
        long num1 = 9, num2 = 1, res = 0;
        while(true)
        {
            if(res + num1 * num2 > k) break;
            res += num1 * num2;
            num1 *= 10;
            num2++;
            cnt++;
        }
        cnt++;
        // pos의 자리
        double pos_d = 0;
        if(cnt == 0) pos_d = 1;
        else pos_d = Math.pow(10, cnt-1);

        int pos = (int)pos_d;
        res++;
        int num = pos;
        while(true)
        {
            if(res > k) break;
            num++;
            res += cnt;
        }

        num--; res -= cnt;
        String num_s = Integer.toString(num);
        char answer = num_s.charAt(k-(int)res);
        System.out.println(answer);
    }

}
