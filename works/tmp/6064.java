import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0)
        {
            String[] _s = br.readLine().split(" ");
            int M = Integer.parseInt(_s[0]);
            int N = Integer.parseInt(_s[1]);
            int x = Integer.parseInt(_s[2]);
            int y = Integer.parseInt(_s[3]);

            int big, small, bigVal, smallVal;
            if(M < N) { big = N; bigVal = y; small = M; smallVal = x;}
            else { big = M; bigVal = x; small = N; smallVal = y;}

            int temp = smallVal;
            int sub = big - small;
            int cnt = 0;
            boolean found = false;

            while(true)
            {
                if(temp == bigVal) {found = true; break;}

                if(temp - sub <= 0)
                {
                    int subTmp = temp - sub;
                    temp = big - (subTmp * -1);
                }
                else temp -= sub;

                if(temp == smallVal) break;

                cnt++;
            }

            if(!found) System.out.println(-1);
            else System.out.println((small * cnt) + smallVal);
        }
    }

}
