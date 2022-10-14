import java.util.*;

public class Main {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] d = new int[1010];
        int n = sc.nextInt();

        d[0] = 0;
        d[1] = 1;
        d[2] = 2;

        for(int i = 3; i <= n; i++)
            d[i] = (d[i-1] + d[i-2]) % 10007;

        System.out.print(d[n]);
    }

}
