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
        boolean[] mark = new boolean[2000010];
        boolean[] students = new boolean[2000010];
        int n = sc.nextInt();
        int c = sc.nextInt();
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            int num = sc.nextInt();
            if(students[num]) continue;
            students[num] = true;
            for(int j = num; j <= c; j+=num)
            {
                if(!mark[j]) 
                {
                    cnt++;
                    mark[j] = true;
                }
            }
        }
        System.out.print(cnt);
    }
}
