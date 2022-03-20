import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import static java.util.Collections.sort;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        ArrayList<Integer> v = new ArrayList<Integer>();
        v.add(Integer.parseInt(_s[0]));
        v.add(Integer.parseInt(_s[1]));
        v.add(Integer.parseInt(_s[2]));
        sort(v);
        System.out.print(v.get(1));
    }
}
