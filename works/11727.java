import java.util.*;

public class Main {

    static int[] d = new int[1010];

    static int dp(int n)
    {
        if(n <= 1) return n;
        if(n == 2) return 3;
        if(d[n] > 0) return d[n];

        d[n] = (dp(n-1) + dp(n-2) * 2) % 10007;
        return d[n];
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(dp(n));
    }

}