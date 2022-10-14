import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num = 1;
        int cnt = 0;
        while(num <= n)
        {
            cnt += (n - num + 1);
            num *= 10;
        }
        System.out.print(cnt);
    }

}
