import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        System.out.println(dfs(A, B, C));
    }

    static long dfs(int a, int b, int c) {
        if(b == 1)
        {
            return a % c;
        }
        long n = dfs(a, b/2, c);
        if(b % 2 == 0)
        {
            return (n * n) % c;
        }
        else
        {
            return (((n * n) % c) * a) % c;
        }
    }
}

