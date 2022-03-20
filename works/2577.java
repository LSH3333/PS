import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int res = a * b * c;
        String res_s = Integer.toString(res);
        int[] mark = new int[10];
        for(int i = 0; i < res_s.length(); i++) mark[res_s.charAt(i)-'0']++;
        for(int i = 0; i < 10; i++) System.out.println(mark[i]);

    }
}
