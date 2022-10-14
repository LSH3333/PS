import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        String[] _s = br.readLine().split(" ");
        int n = Integer.parseInt(_s[0]);
        int m = Integer.parseInt(_s[1]);
        _s = br.readLine().split(" ");
        int ans = 0, ansSub = 99999999;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                for(int k = j+1; k < n; k++)
                {
                    int sum = Integer.parseInt(_s[i]) + Integer.parseInt(_s[j]) + Integer.parseInt(_s[k]);
                    if(sum <= m && m-sum < ansSub)
                    {
                        ansSub = m - sum;
                        ans = sum;
                    }
                }
            }
        }
        System.out.print(ans);
    }
}
