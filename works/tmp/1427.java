import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        Integer[] v = new Integer[num.length()];
        for(int i = 0; i < num.length(); i++) v[i] = num.charAt(i)-'0';
        Arrays.sort(v, Collections.reverseOrder());
        for(int x : v) System.out.print(x);
    }
}
