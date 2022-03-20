import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int a =  sc.nextInt();
        int b =  sc.nextInt();
        int c =  sc.nextInt();
        int d =  sc.nextInt();
        int e =  sc.nextInt();

        int res1 = Math.min(a, Math.min(b,c));
        int res2 = Math.min(d, e);
        System.out.print(res1+res2-50);
    }


}
