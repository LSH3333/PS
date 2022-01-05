import java.util.*;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[100001];
        int[] d = new int[100001];
        int n = sc.nextInt();

        for(int i = 0; i < n; i++)
        {
            int num = sc.nextInt();
            a[i] = num;
        }

        d[0] = a[0];
        int answer = d[0];
        for(int i = 1; i < n; i++)
        {
            d[i] = Math.max(d[i-1] + a[i], a[i]);
            answer = Math.max(answer, d[i]);
        }

        System.out.print(answer);
    }

}
