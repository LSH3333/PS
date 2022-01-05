import java.util.*;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int[] d = new int[1010];
        d[1] = 1;
        d[2] = 2;

        for(int i = 1; i <= 1000; i++)
        {
            int sum = 0;
            for(int j = 1; j <= i/2; j++) sum += d[j];
            d[i] = sum + 1;
        }

        int t = sc.nextInt();
        while(t-- > 0)
        {
            int n = sc.nextInt();
            System.out.println(d[n]);
        }
    }

}
