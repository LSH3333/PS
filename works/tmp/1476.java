import java.sql.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int E, S, M;
        E = sc.nextInt(); S = sc.nextInt(); M = sc.nextInt();
        int cnt = 1;

        int e = 1, s = 1, m = 1;
        while(true)
        {
            if(e == E && s == S && m == M) break;
            cnt++;

            if(e < 15) e++;
            else e = 1;

            if(s < 28) s++;
            else s = 1;

            if(m < 19) m++;
            else m = 1;
        }
        System.out.print(cnt);
    }
}
