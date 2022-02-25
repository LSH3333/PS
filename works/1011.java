import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    static long dfs(long distance, long moved, long cnt)
    {
        if(distance == 0) return cnt;

        for(long move = moved+1; move >= moved-1; move--)
        {
            if(move <= 0) continue;
            long sum = (move * (move + 1)) / 2;
            if(sum <= distance)
            {
                return dfs(distance-move, move, cnt+1);
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        String[] _s;
        while(t-- > 0)
        {
            _s = br.readLine().split(" ");
            long x = Integer.parseInt(_s[0]);
            long y = Integer.parseInt(_s[1]);
            long distance = y - x;
            long ans = dfs(distance, 0, 0);
            System.out.println(ans);
        }

    }

}
